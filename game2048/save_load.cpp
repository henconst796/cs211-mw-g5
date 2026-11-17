#include <iostream>
#include <fstream>
#include <string>
#include "save_load.h"
using namespace std;

const string SAVE_FILE = "savegame.txt";
const string MARKER = "CS211_2048_V1";

bool is_valid_tile(int value)
{
    if (value == 0)
    {
        return true;
    }
    if (value < 2)
    {
        return false;
    }

    while (value % 2 == 0)
    {
        value = value / 2;
    }
    return value == 1;
}

bool save_game(int board[][5], int score, int moves)
{
    ofstream out(SAVE_FILE);
    if (!out)
    {
        cout << "Save failed: could not write " << SAVE_FILE << "." << endl;
        return false;
    }

    out << MARKER << endl;
    out << score << " " << moves << endl;
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            out << board[r][c];
            if (c < 4)
            {
                out << " ";
            }
        }
        out << endl;
    }

    out.close();
    if (!out)
    {
        cout << "Save failed: an error happened while writing " << SAVE_FILE << "." << endl;
        return false;
    }

    cout << "Game saved to " << SAVE_FILE << " (this replaces any earlier save)." << endl;
    return true;
}

bool load_game(int board[][5], int& score, int& moves)
{
    ifstream in(SAVE_FILE);
    if (!in)
    {
        cout << "Load failed: " << SAVE_FILE << " was not found. Your current game was not changed." << endl;
        return false;
    }

    string marker;
    int tempScore;
    int tempMoves;
    int tempBoard[5][5];
in >> marker;
    if (marker != MARKER)
    {
        cout << "Load failed: the first line must be " << MARKER << ". Your current game was not changed." << endl;
        return false;
    }

    if (!(in >> tempScore >> tempMoves))
    {
        cout << "Load failed: the score and move count are missing or not whole numbers. Your current game was not changed." << endl;
        return false;
    }
    if (tempScore < 0 || tempMoves < 0)
    {
        cout << "Load failed: the score and move count can't be negative. Your current game was not changed." << endl;
        return false;
    }

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (!(in >> tempBoard[r][c]))
            {
                cout << "Load failed: the board needs exactly 25 whole numbers. Your current game was not changed." << endl;
                return false;
            }
            if (!is_valid_tile(tempBoard[r][c]))
            {
                cout << "Load failed: board values must be 0 or a power of two (2, 4, 8, ...). Your current game was not changed." << endl;
                return false;
            }
        }
    }

    string extra;
    if (in >> extra)
    {
        cout << "Load failed: there is extra content after the board. Your current game was not changed." << endl;
        return false;
    }

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            board[r][c] = tempBoard[r][c];
        }
    }
    score = tempScore;
    moves = tempMoves;

    cout << "Game loaded from " << SAVE_FILE << "." << endl;
    return true;
}