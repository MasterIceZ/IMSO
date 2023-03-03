/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

const int MxN = 200020;
vector<int> adj[MxN];
int dp[MxN];
map<map<int, int>, int> hash_table;
vector<map<int, int>> mem;

void dfs(int u, int p){
	map<int, int> t;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
		t[dp[x]]++;
	}
	if(hash_table.count(t) == false){
		hash_table[t] = mem.size();
		mem.emplace_back(t);
	}
	dp[u] = hash_table[t];
	return ;
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1, 0);
	int u = dp[1];
	bool done = false;
	while(true){
		int state = -1;
		for(auto x: mem[u]){
			if(x.second & 1){
				if(state == -1){
					state = x.first;
				}
				else{
					cout << "NO";
					done = true;
					break;
				}
			}
		}
		if(done){
			break;
		}
		if(state == -1 || state == 1){
			cout << "Yes";
			break;
		}
		else{
			u = state;
		}
	}
	hash_table.clear();
	mem.clear();
	for(int i=1; i<=n; ++i){
		adj[i].clear();
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1, cnt = 0;
	cin >> q;
	while(q--){
		cerr << "===== Question #" << ++cnt << " =====\n";
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
