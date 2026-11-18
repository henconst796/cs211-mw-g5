#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "2048_helper.h"
#include "save_load.h"
using namespace std;

int main()
{
    srand(time(0));

    int board[5][5];
    int score = 0;
    int moves = 0;
    new_game(board, score, moves);

    cout << "Welcome to 2048!" << endl;
    print_help();
    show_game(board, score, moves);

    string line;
    while (true)
    {
        cout << "Choice (u, d, l, r, s, o, n, h, e): ";
        if (!getline(cin, line))
        {
            cout << endl << "No more input. Goodbye!" << endl;
            break;
        }

        if (line.length() != 1)
        {
            cout << "Invalid command. Type one letter, or h for help." << endl;
            continue;
        }
        char choice = line[0];

        if (choice == 'u' || choice == 'd' || choice == 'l' || choice == 'r')
        {
            if (!can_move(board))
            {
                cout << "Game over: no moves are possible. You can still save (s), load (o), start a new game (n), get help (h) or exit (e)." << endl;
                continue;
            }

            int highestBefore = highest_tile(board);
            bool changed = false;

            if (choice == 'u')
                changed = move_up(board, score);
            else if (choice == 'd')
                changed = move_down(board, score);
            else if (choice == 'l')
                changed = move_left(board, score);
            else
                changed = move_right(board, score);

            if (changed)
            {
                insert_random(board);
                moves++;
                show_game(board, score, moves);

                if (highestBefore < 2048 && highest_tile(board) >= 2048)
                {
                    cout << "You made a 2048 tile. You win! You can keep playing." << endl;
                }
            }
else
            {
                cout << "Nothing moved, so no new tile was added." << endl;
            }
        }
        else if (choice == 's')
        {
            save_game(board, score, moves);
        }
        else if (choice == 'o')
        {
            if (load_game(board, score, moves))
            {
                show_game(board, score, moves);
            }
        }
        else if (choice == 'n')
        {
            cout << "Start a new game? Your current game will be lost. (y/n): ";
            string answer;
            if (getline(cin, answer) && answer == "y")
            {
                new_game(board, score, moves);
                show_game(board, score, moves);
            }
            else
            {
                cout << "New game cancelled." << endl;
            }
        }
        else if (choice == 'h')
        {
            print_help();
        }
        else if (choice == 'e')
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid command. Type one letter, or h for help." << endl;
        }
    }

    return 0;
}
