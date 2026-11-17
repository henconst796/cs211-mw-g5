#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "2048_helper.h"
using namespace std;

// Copies every cell of board into copy (used to remember the board before a move)
void copy_board(int board[][5], int copy[][5], int numrows)
{
    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            copy[r][c] = board[r][c];
        }
    }
}

// Returns true if the two boards are different in at least one cell
bool boards_differ(int a[][5], int b[][5], int numrows)
{
    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (a[r][c] != b[r][c])
            {
                return true;
            }
        }
    }
    return false;
}

bool move_left(int board[][5], int& score, int numrows)
{
    int before[5][5];
    copy_board(board, before, numrows);   // remember the board so we can tell if it changed

    for (int r = 0; r < numrows; r++)
    {
        // Step 1: slide every tile as far left as it can go
        int columns = 0;   // the next free spot from the left
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] != 0)
            {
                if (c != columns)
                {
                    board[r][columns] = board[r][c];
                    board[r][c] = 0;
                }
                columns++;
            }
        }

        // Step 2: merge equal neighbors, going left to right
        for (int c = 0; c < 4; c++)
        {
            if (board[r][c] != 0 && board[r][c] == board[r][c + 1])
            {
                board[r][c] = board[r][c] * 2;
                score = score + board[r][c];   // the new tile's value is added to the score
                board[r][c + 1] = 0;           // the emptied spot can't merge again this move
            }
        }

        // Step 3: slide again to close the gaps the merges left behind
        columns = 0;
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] != 0)
            {
                if (c != columns)
                {
                    board[r][columns] = board[r][c];
                    board[r][c] = 0;
                }
                columns++;
            }
        }
    }

    return boards_differ(board, before, numrows);
}

bool move_right(int board[][5], int& score, int numrows)
{
    int before[5][5];
    copy_board(board, before, numrows);

    for (int r = 0; r < numrows; r++)
    {
        // Step 1: slide every tile as far right as it can go
        int columns = 4;   // the next free spot from the right
        for (int c = 4; c >= 0; c--)
        {
            if (board[r][c] != 0)
            {
                if (c != columns)
                {
                    board[r][columns] = board[r][c];
                    board[r][c] = 0;
                }
                columns--;
            }
        }

        // Step 2: merge equal neighbors, going right to left
        for (int c = 4; c > 0; c--)
        {
            if (board[r][c] != 0 && board[r][c] == board[r][c - 1])
            {
                board[r][c] = board[r][c] * 2;
                score = score + board[r][c];
                board[r][c - 1] = 0;
            }
        }

        // Step 3: slide again to close the gaps
        columns = 4;
        for (int c = 4; c >= 0; c--)
        {
            if (board[r][c] != 0)
            {
                if (c != columns)
                {
                    board[r][columns] = board[r][c];
                    board[r][c] = 0;
                }
                columns--;
            }
        }
    }

    return boards_differ(board, before, numrows);
}

bool move_up(int board[][5], int& score, int numrows)
{
    int before[5][5];
    copy_board(board, before, numrows);

    for (int c = 0; c < 5; c++)
    {
        // Step 1: slide every tile in this column as far up as it can go
        int rows = 0;   // the next free spot from the top
        for (int r = 0; r < numrows; r++)
        {
            if (board[r][c] != 0)
            {
                if (r != rows)
                {
                    board[rows][c] = board[r][c];
                    board[r][c] = 0;
                }
                rows++;
            }
        }

        // Step 2: merge equal neighbors, going top to bottom
        for (int r = 0; r < numrows - 1; r++)
        {
            if (board[r][c] != 0 && board[r][c] == board[r + 1][c])
            {
                board[r][c] = board[r][c] * 2;
                score = score + board[r][c];
                board[r + 1][c] = 0;
            }
        }

        // Step 3: slide again to close the gaps
        rows = 0;
        for (int r = 0; r < numrows; r++)
        {
            if (board[r][c] != 0)
            {
                if (r != rows)
                {
                    board[rows][c] = board[r][c];
                    board[r][c] = 0;
                }
                rows++;
            }
        }
    }

    return boards_differ(board, before, numrows);
}

bool move_down(int board[][5], int& score, int numrows)
{
    int before[5][5];
    copy_board(board, before, numrows);

    for (int c = 0; c < 5; c++)
    {
        // Step 1: slide every tile in this column as far down as it can go
        int rows = numrows - 1;   // the next free spot from the bottom
        for (int r = numrows - 1; r >= 0; r--)
        {
            if (board[r][c] != 0)
            {
                if (r != rows)
                {
                    board[rows][c] = board[r][c];
                    board[r][c] = 0;
                }
                rows--;
            }
        }

        // Step 2: merge equal neighbors, going bottom to top
        for (int r = numrows - 1; r > 0; r--)
        {
            if (board[r][c] != 0 && board[r][c] == board[r - 1][c])
            {
                board[r][c] = board[r][c] * 2;
                score = score + board[r][c];
                board[r - 1][c] = 0;
            }
        }

        // Step 3: slide again to close the gaps
        rows = numrows - 1;
        for (int r = numrows - 1; r >= 0; r--)
        {
            if (board[r][c] != 0)
            {
                if (r != rows)
                {
                    board[rows][c] = board[r][c];
                    board[r][c] = 0;
                }
                rows--;
            }
        }
    }

    return boards_differ(board, before, numrows);
}

void print_board(int board[][5], int numrows)
{
    cout << endl << "\t-----------------------------------------" << endl;

    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] > 0)
                cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
            else
                cout << "\t|" << right << setw(6) << setfill(' ') << " ";
        }
        cout << "\t|" << endl;
        cout << "\t-----------------------------------------" << endl;
    }

    cout << "\t" << endl << endl;
}

void insert_random(int board[][5], int numrows)
{
    // Count the empty cells first, so we never loop forever on a full board
    int empty_count = 0;
    for (int row = 0; row < numrows; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            if (board[row][col] == 0)
                empty_count++;
        }
    }

    if (empty_count > 0)
    {
        while (true)
        {
            // Pick a random cell
            int r = rand() % numrows;
            int c = rand() % 5;
            // Use it only if it's empty
            if (board[r][c] == 0)
            {
                board[r][c] = 2 * (1 + (rand() % 2));
                break;
            }
        }
    }
}
