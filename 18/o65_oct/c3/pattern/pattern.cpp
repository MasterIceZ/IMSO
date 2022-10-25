#include "pattern.h"
#include <bits/stdc++.h>

const int MxN = 200020;
const long long MOD = 1e9 + 7;

std::vector<int> adj[MxN];
std::bitset<MxN> is_leaf, visited;
int level[MxN];

void get_leaves(int u, int p, int lv){
	bool gone = false;
	level[u] = lv;
	for(auto x: adj[u]){
		if(visited[x] || x == p){
			continue;
		}
		gone = true;
		get_leaves(x, u, lv + 1);
	}
	is_leaf[u] = !gone;
}

long long mod_of_power(int a, int b){
	if(b == 0){
		return 1ll;
	}
	if(a == 1){
		return 1ll;
	}
	long long t = mod_of_power(a, b / 2);
	t = (t * t) % MOD;
	if(b % 2 == 1){
		t = (t * a) % MOD;
	}
	return t;
}

int total_pattern(int N, int M, std::vector<std::vector<int> >Path, std::vector<std::vector<int> >p)
{
	if(M == 1){
		return 1;
	}
	for(int i=0; i<(int) Path.size(); ++i){
		int u = Path[i][0], v = Path[i][1];
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	get_leaves(0, -1, 1);
	int max_leaf = 0;
	for(int i=0; i<N; ++i){
		if(!is_leaf[i]){
			continue;
		}
		max_leaf = std::max(max_leaf, level[i]);
	}
	long long pp = 0ll, res = 0ll;
	int cnt = 0;
	for(int i=0; i<N; ++i){
		if(!is_leaf[i]){
			continue;
		}
		if(level[i] == max_leaf){
			max_leaf = -1;
			pp = (pp + 1ll) % MOD;
		}
		else{
			pp = (pp + 2ll) % MOD;
			cnt++;
		}
	}
	res = (pp * mod_of_power(2, cnt)) % MOD;
	return res;
}
