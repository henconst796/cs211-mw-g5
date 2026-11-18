#ifndef HELPER_2048_H
#define HELPER_2048_H

// Each move slides and merges the tiles in one direction.
// It returns true if the board changed, and adds the points it earned to score.
bool move_left(int board[][5], int &score, int numrows = 5);
bool move_right(int board[][5], int &score, int numrows = 5);
bool move_up(int board[][5], int &score, int numrows = 5);
bool move_down(int board[][5], int &score, int numrows = 5);

// Prints the board as a grid
void print_board(int board[][5], int numrows = 5);

// Puts one new tile in a random empty cell
void insert_random(int board[][5], int numrows = 5);

void new_game(int board[][5], int &score, int &moves);
int highest_tile(int board[][5]);
bool can_move(int board[][5]);
void show_game(int board[][5], int score, int moves);
void print_help();

#endif