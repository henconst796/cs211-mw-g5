#include <iostream>
#include "2048_helper.h"
using namespace std;

int main()
{
    int size = 5;
    int board[5][5] = {
        {0, 4, 2, 4, 0},
        {0, 0, 0, 0, 0},
        {2, 0, 2, 0, 2},
        {0, 0, 2, 0, 0},
        {2, 2, 2, 2, 2},
    };
    int score = 0;

    cout << "Initial Board : [5x5] :" << endl;
    print_board(board);
    cout << "Score: " << score << endl;

    char choice = 'u';   // initialized
    while (choice != 'e')
    {
        cout << "Please enter choice:{u,d,l,r,e} for UP, DOWN, LEFT, RIGHT, Exit: " << endl;
        cout << "Choice: ";
        cin >> choice;

        bool changed = false;   // did the move actually change the board?

        if (choice == 'u')
            changed = move_up(board, score, size);
        else if (choice == 'd')
            changed = move_down(board, score, size);
        else if (choice == 'l')
            changed = move_left(board, score, size);
        else if (choice == 'r')
            changed = move_right(board, score, size);

        // Only add a new tile after a move that changed the board
        if (changed)
        {
            insert_random(board, size);
        }

        print_board(board);
        cout << "Score: " << score << endl;
    }

    return 0;
}
