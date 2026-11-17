#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H
bool save_game(int board[][5], int score, int moves);
bool load_game(int board[][5], int& score, int& moves);
#endif