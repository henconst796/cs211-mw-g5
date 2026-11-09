#include <iostream>
#include <random>
#include <iomanip>
#include <cstdlib>
using namespace std;

void move_left(int board[][5], int numrows = 5)
{
	for (int r = 0; r < numrows; r++)
	{
		int columns = 0;
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

		for (int c = 0; c < 4; c++)
		{
			if (board[r][c] != 0 && board[r][c] == board[r][c + 1])
			{
				board[r][c] *= 2;
				board[r][c + 1] = 0;
			}
		}
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
}


void move_right(int board[][5], int numrows = 5)
{
	for (int r = 0; r < numrows; r++)
	{
		int columns = 4;
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
		for (int c = 4; c > 0; c--)
		{
			if (board[r][c] != 0 && board[r][c] == board[r][c - 1])
			{
				board[r][c] *= 2;
				board[r][c - 1] = 0;
			}
		}
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
}


void move_up(int board[][5], int numrows = 5)
{
    for (int c = 0; c < 5; c++)
	{
        int columns = 0;
	    for (int r = 0; r < numrows; r++)
	    {
	        if (board[r][c] != 0)
	        {
	        if (r != columns)
            {
	           board[columns][c] = board[r][c];
	           board[r][c] = 0;
	        }
	            columns++;
	       }
	   }
	for (int r = 0; r < numrows - 1; r++)
	    {
		    if (board[r][c] != 0 && board[r][c] == board[r + 1][c])
			{
				board[r][c] *= 2;
				board[r + 1][c] = 0;
			}
		}
		    columns = 0;
		    for (int r = 0; r < numrows; r++)
		{
			if (board[r][c] != 0)
			{
			if (r != columns)
			{
				board[columns][c] = board[r][c];
				board[r][c] = 0;
			}
			columns++;
			}
		}
	}
}


void move_down(int board[][5], int numrows = 5)
{
	for (int c = 0; c < 5; c++)
	{
	    int columns = numrows - 1;
	    for (int r = numrows - 1; r >= 0; r--)
	        {
		        if (board[r][c] != 0)
			{
				if (r != columns)
				{
				    board[columns][c] = board[r][c];
					board[r][c] = 0;
				}
				columns--;
			}
		}
		for (int r = numrows - 1; r > 0; r--)
		{
			if (board[r][c] != 0 && board[r][c] == board[r - 1][c])
			{
				board[r][c] *= 2;
				board[r - 1][c] = 0;
			}
		}
		columns = numrows - 1;
		for (int r = numrows - 1; r >= 0; r--)
		{
			if (board[r][c] != 0)
			{
				if (r != columns)
				{
					board[columns][c] = board[r][c];
					board[r][c] = 0;
				}
				columns--;
			}
		}
	}
}



void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}


void insert_random(int board[][5], int numrows = 5)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//add number randomly {2,4}
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}

	}
}

