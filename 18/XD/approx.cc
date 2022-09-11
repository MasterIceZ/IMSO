
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
 
// const int MxN = 1e6 + 10;
// vector<int> adj[MxN];
vector<vector<int>> adj;
queue<int> q;
// int c[MxN];
vector<int> c;
 
inline void name(int idx, int compo){
	q.emplace(idx);
	c[idx] = compo;
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(auto x: adj[now]){
			if(c[x]){
				continue;
			}
			c[x] = compo;
			q.emplace(x);
		}
	}
}
 
void name_2(int u, int p, int cc){
	c[u] = cc;
	for(auto x: adj[u]){
		if(x == p || c[x]){
			continue;
		}
		name_2(x, u, cc);
	}
}
 
inline void solution(){
	int n, m, q, a, b;
//	cin >> n >> m >> q;
	scanf("%d %d %d", &n, &m, &q);
	c.resize(n + 10);
	adj.resize(n + 10);
	for(int i=1; i<=m; ++i){
//		cin >> a >> b;
		scanf("%d %d", &a, &b);
		adj[a].emplace_back(b); adj[b].emplace_back(a);
	}
	int it = 0;	
	for(int i=1; i<=q; ++i){
//		cin >> a >> b;
		scanf("%d %d", &a, &b);
		if(!c[a]){
			name_2(a, 0, ++it);
		}
		if(!c[b]){
			name_2(b, 0, ++it);
		}
//		cout << (c[a] == c[b] ? "Y": "N") << "\n";
		printf("%s\n", (c[a] == c[b] ? "Y": "N"));
	}
	return ;
}
 
signed main(){
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
