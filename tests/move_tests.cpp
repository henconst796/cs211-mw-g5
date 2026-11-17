// Movement tests for 2048.
// These call the move functions directly, with no random tiles,
// so the results are always the same every time you run it.
//
// Build and run from the main project folder:
//   g++ -std=c++17 -Wall -Wextra -pedantic tests/move_tests.cpp game2048/2048_helper.cpp -o move_tests
//   .\move_tests
#include <iostream>
#include <string>
#include "../game2048/2048_helper.h"
using namespace std;

int passed = 0;   // how many tests passed
int total = 0;    // how many tests ran

// Prints 5 numbers like: 2 2 4 0 0
void print_line(int values[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << values[i];
        if (i < 4)
        {
            cout << " ";
        }
    }
}

// Puts the 5 start values into row 0 (for left/right) or column 0 (for up/down),
// does ONE move, then checks the result, the score gained, and "changed".
// Prints PASS or FAIL and updates the passed/total counters.
void check(string direction, int start[5], int expected[5], int expectedScore, bool expectedChanged)
{
    int board[5][5];
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            board[r][c] = 0;
        }
    }

    bool vertical = (direction == "up" || direction == "down");
    for (int i = 0; i < 5; i++)
    {
        if (vertical)
            board[i][0] = start[i];   // column 0, top to bottom
        else
            board[0][i] = start[i];   // row 0, left to right
    }

    int score = 0;
    bool changed = false;
    if (direction == "left")
        changed = move_left(board, score);
    else if (direction == "right")
        changed = move_right(board, score);
    else if (direction == "up")
        changed = move_up(board, score);
    else
        changed = move_down(board, score);

    int result[5];
    for (int i = 0; i < 5; i++)
    {
        if (vertical)
            result[i] = board[i][0];
        else
            result[i] = board[0][i];
    }

    bool ok = (score == expectedScore && changed == expectedChanged);
    for (int i = 0; i < 5; i++)
    {
        if (result[i] != expected[i])
        {
            ok = false;
        }
    }

    total++;
    if (ok)
    {
        passed++;
        cout << "PASS  ";
    }
    else
    {
        cout << "FAIL  ";
    }
    cout << direction << ": ";
    print_line(start);
    cout << "  ->  ";
    print_line(result);
    cout << "   score +" << score << "   changed: ";
    if (changed)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    if (ok == false)
    {
        cout << "      expected: ";
        print_line(expected);
        cout << "   score +" << expectedScore << endl;
    }
}

int main()
{
    // Each test: start values, expected values, expected score, expected "changed"
    int s1[5] = {0, 2, 0, 2, 0};       int e1[5] = {4, 0, 0, 0, 0};
    int s2[5] = {2, 2, 2, 0, 0};       int e2[5] = {4, 2, 0, 0, 0};
    int s3[5] = {2, 2, 2, 2, 2};       int e3[5] = {4, 4, 2, 0, 0};
    int s4[5] = {2, 2, 4, 0, 0};       int e4[5] = {4, 4, 0, 0, 0};
    int s5[5] = {4, 4, 8, 8, 0};       int e5[5] = {8, 16, 0, 0, 0};
    int s6[5] = {2, 4, 8, 0, 0};       int e6[5] = {2, 4, 8, 0, 0};
    int s7[5] = {2, 2, 2, 2, 0};       int e7[5] = {4, 4, 0, 0, 0};
    int s8[5] = {0, 0, 2, 0, 4};       int e8[5] = {2, 4, 0, 0, 0};
    int s9[5] = {2, 2, 2, 0, 0};       int e9[5] = {0, 0, 0, 2, 4};
    int s10[5] = {4, 0, 4, 0, 4};      int e10[5] = {0, 0, 0, 4, 8};
    int s11[5] = {1024, 1024, 0, 0, 0}; int e11[5] = {0, 0, 0, 0, 2048};
    int s12[5] = {0, 2, 0, 2, 0};      int e12[5] = {4, 0, 0, 0, 0};
    int s13[5] = {2, 2, 4, 0, 0};      int e13[5] = {4, 4, 0, 0, 0};
    int s14[5] = {2, 2, 2, 0, 0};      int e14[5] = {0, 0, 0, 2, 4};
    int s15[5] = {0, 0, 0, 0, 2};      int e15[5] = {0, 0, 0, 0, 2};

    cout << "2048 movement tests (no random tiles)" << endl;
    cout << "-------------------------------------" << endl;

    check("left", s1, e1, 4, true);   // slides through gaps
    check("left", s2, e2, 4, true);   // three equal tiles
    check("left", s3, e3, 8, true);   // five equal tiles
    check("left", s4, e4, 4, true);   // new 4 must not merge again
    check("left", s5, e5, 24, true);   // two merges in one move
    check("left", s6, e6, 0, false);   // nothing can move
    check("left", s7, e7, 8, true);   // four equal tiles
    check("left", s8, e8, 0, true);   // slide with no merge
    check("right", s9, e9, 4, true);   // right merges the rightmost pair
    check("right", s10, e10, 8, true);   // right through gaps
    check("right", s11, e11, 2048, true); // reaching 2048
    check("up", s12, e12, 4, true);   // up through gaps
    check("up", s13, e13, 4, true);   // up, no double merge
    check("down", s14, e14, 4, true);   // down merges the bottom pair
    check("down", s15, e15, 0, false);   // already at the bottom

    cout << "-------------------------------------" << endl;
    cout << passed << " of " << total << " tests passed" << endl;
    return 0;
}
