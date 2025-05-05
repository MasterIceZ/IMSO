#include "wall.h"

struct node_t {
	int mn = 1e9 + 100, mx = 0;
};

struct segment_tree {
	node_t t[MxN << 2];

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
	build(1, n, 1);	
	return;
}

