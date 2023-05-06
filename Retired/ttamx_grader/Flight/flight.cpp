#include <bits/stdc++.h>
#include "flight.h"

using namespace std;

const int MxN = 100010;
vector<int> adj[MxN], rev[MxN];
bitset<MxN> from_1, from_n;
int n;

void initialize(int N, int Q){
	n = N;
	from_1[1] = true;
	from_n[n] = true;
    return;
}

void dfs(int u, int p){
	from_1[u] = true;
	for(auto x: adj[u]){
		if(from_1[x] == true || x == p){
			continue;
		}
		dfs(x, u);
	}
}

void dfs_rev(int u, int p){
	from_n[u] = true;
	for(auto x: rev[u]){
		if(from_n[x] == true || x == p){
			continue;
		}
		dfs_rev(x, u);
	}
}

void add(int u, int v){
	adj[u].emplace_back(v);
	rev[v].emplace_back(u);
	if(from_1[u] && !from_1[v]){
		dfs(v, u);
	}
	if(from_n[v] && !from_n[u]){
		dfs_rev(u, v);
	}
    return;
}

int ask(int k){
	// from 1 -> k -> n
	return (from_1[k] && from_n[k]);
}
