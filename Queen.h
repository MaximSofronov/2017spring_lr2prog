#pragma once

#include <iostream>

const int SIZE = 4;

inline int board[SIZE][SIZE]; //доска
inline int resultsCount = 0;
inline int quantity = 0;
inline int m=INT_MAX; //минимальное количество ферзей
inline int tmp=0; //счётчик для пропуска строк
inline bool a=false;


void set_queen(int i, int j);
void reset_queen(int i, int j);
void try_to_set_queen(int i);
void show_board();
void null_board();
void check_result();
void result();