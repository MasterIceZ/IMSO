#include "gridcoloring.h"

#include <algorithm>
#include <vector>

const int MxN = 11;
const int INF = 1e9 + 100;

int left_x[MxN], first_x_four[MxN];

void init_grid(int X, int Y, int Q, std::vector<std::vector<char>> G){
	for(int i=1; i<=Y; ++i) {
		first_x_four[i] = INF;
		for(int x=0; x<X; ++x) {
			bool have_X = false;
			for(int y=0; y<i; ++y) {
				if(G[x][y] == 'X') {
					have_X = true;
				}
			}
			if(have_X) {
				first_x_four[i] = std::min(first_x_four[i], x + 1);
			}
		}
		for(int x=0; x<X; ++x) {
			bool four = false;
			for(int y=0; y<i-1; ++y) {
				if(G[x][y] == '/') {
					for(int nxt_y=y+1; nxt_y<i; ++nxt_y) {
						if(G[x][nxt_y] == '\\') {
							four = true;
							break;
						}
						if(G[x][nxt_y] != '?') {
							break;
						}
					}
				}
				if(four) {
					break;
				}
			}
			if(!four && x > 0) {
				for(int y=0; y<i; ++y) {
					if(G[x - 1][y] == '\\' && G[x][y] == '/') {
						four = true;
						break;
					}
				}
			}
			if(four) {
				first_x_four[i] = std::min(first_x_four[i], x + 1);
			}
		}
	}
	for(int i=2;i<=Y; ++i) {
		first_x_four[i] = std::min(first_x_four[i], first_x_four[i - 1]);
	}
}

int answer_query(int x1, int y1, int x2, int y2){
    if(x2 == 0 && y2 == 0) {
		return 1;
	}
	if(x2 == 0 || y2 == 0) {
		return 2;
	}
	if(x2 >= first_x_four[y2]) {
		return 4;
	}
	return 3;
}

