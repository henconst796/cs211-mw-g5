#include <iostream>
#include "2048_helper.h"
#include "save_load.h"
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
    int moves = 0;

    cout << "Initial Board : [5x5] :" << endl;
    print_board(board);
    cout << "Score: " << score << "   Moves: " << moves << endl;

    char choice = 'u';   // initialized
    while (choice != 'e')
    {
        cout << "Please enter choice:{u,d,l,r,s,o,e} for UP, DOWN, LEFT, RIGHT, Save, Open (load), Exit: " << endl;
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
        else if (choice == 's')
            save_game(board, score, moves);
        else if (choice == 'o')
            load_game(board, score, moves);

        // Only add a new tile after a move that changed the board
        if (changed)
        {
            insert_random(board, size);
            moves++;
        }

        print_board(board);
        cout << "Score: " << score << "   Moves: " << moves << endl;
    }

    return 0;
}