#include "Queen.h"

void set_queen(int i, int j) {//ставим ферзя и заполняем ячейки, которые ферзь будет бить
    for (int x = 0; x < SIZE; x++) {
        board[x][j]++;//горизонталь
        board[i][x]++;//вертикаль
        int t = j - i + x;
        if (t >= 0 && t < SIZE) {//диагональ
            board[x][t]++;
        }
        t = j + i - x;
        if (t >= 0 && t < SIZE) {
            board[x][t]++;//диагональ
        }
    }
    board[i][j] = -1;
}

void reset_queen(int i, int j) {
    for (int x = 0; x < SIZE; x++) {
        board[x][j]--;//горизонталь
        board[i][x]--;//вертикаль
        int t = j - i + x;//диагональ
        if (t >= 0 && t < SIZE) {
            board[x][t]--;
        }
        t = j + i - x;
        if (t >= 0 && t < SIZE) {
            board[x][t]--;
        }
    }
    board[i][j] = 0;
}

void result() {
    if (quantity<=m) {
        resultsCount++;
        m = quantity;
        if (a) {
            for (int i = 0; i < SIZE; i++) {
                std::cout << "___";
            }
            std::cout << std::endl;
            show_board();
        }

    }
}

void try_to_set_queen(int i) {

    check_result();

    for (int j = 0; j < SIZE; j++) {
        if (board[i][j] == 0 && i < SIZE) {
            set_queen(i, j);
            quantity++;

            try_to_set_queen(i + 1);
            reset_queen(i,j);
            quantity--;
        }
        tmp++;
        if (tmp==SIZE-1) {

            try_to_set_queen(i + 1);
            tmp=0;
        }


    }
}

void show_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == -1) {
                std::cout << " w ";
            } else {
                std::cout << " . ";
            }
        }
        std::cout << std::endl;
    }
}

void null_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void check_result() {
        int t=0;
        for (int i = 0; i<SIZE; i++) {
            for (int k = 0; k<SIZE; k++) {
                if (board[i][k]!=0 && board[i][k]<=SIZE) {
                    t++;
                }
            }
        }

        if (t == SIZE*SIZE) {
            result();
            return;
        }
}