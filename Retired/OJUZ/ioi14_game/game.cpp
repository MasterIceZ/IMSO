#include "game.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 1550;
int a[MxN][MxN], cnt[MxN];

void initialize(int n) {
	for(int i=0; i<n; ++i){
		for(int j=i+1; j<n; ++j){
			a[i][j] = -1;
		}
		cnt[i] = 0;
	}
}

int hasEdge(int u, int v) {
	if(u > v){
		swap(u, v);
	}
	if(a[u][v] != -1){
		return a[u][v];
	}
	if(++cnt[v] == v){
		a[u][v] = 1;
	}
	else{
		a[u][v] = 0;
	}
	return a[u][v];
}
