#ifndef HEURISTICS_H
#define HEURISTICS_H

int get_row(int x,int s);
int get_column(int x,int s);
int manhattan(int board[],int s);
float euc_sq(int *board,int s);
int max_h(int *board, int s);

#endif