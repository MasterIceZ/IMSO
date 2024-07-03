#include <bits/stdc++.h>

#ifndef ICY
#include "inaho.h"
#endif

int parent[MxN], sz[MxN];
stack<pair<int, int>> st;

int find_root(int u) {
	while(parent[u] != u) {
		u = parent[u];
	}
	return u;
}

void Init(int N) {
	for(int i=1; i<=N; ++i) {
		parent[i] = i;
		sz[i] = i;
	}
}

void AddEdge(int U, int V) {
	if(find_root(U) == find_root(V)) {
		return ;
	}
}

void RemoveLastEdge() {

}

int GetSize(int u) {

}

#ifdef ICY
signed main(int argc, char *argv[]) {
	
}
#endif

// DMOJ
