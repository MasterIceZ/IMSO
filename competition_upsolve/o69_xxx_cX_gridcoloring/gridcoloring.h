#ifndef _GRIDCOLORING_H_INCLUDED
#define _GRIDCOLORING_H_INCLUDED
#include <vector>

void init_grid(int X, int Y, int Q, std::vector<std::vector<char>> G);

int answer_query(int x1, int y1, int x2, int y2);

#endif
