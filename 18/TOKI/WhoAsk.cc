/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Who Asked?
 * ALGO		:
 * DATE		: 4 Oct 2022
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

const ll MOD = 998244353;
const int MxN = 100010;

ll a[MxN];
vector<int> adj[MxN];
queue<int> q;
int idx[MxN], parent[MxN], most_left_child[MxN], most_right_child[MxN];

void bfs(int stp){
	q.emplace(stp);
	int it = 0;
	idx[stp] = ++it;
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(auto x: adj[now]){
			if(idx[x]){
				continue;
			}
			idx[x] = ++it;
			if(!most_left_child[u]){
				most_left_child[u] = idx[x];
			}
			most_right_child[u] = idx[x];
			q.emplace(x);
		}
	}
}

inline void solution(){
	int n, q;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v); 
		adj[v].emplace_back(u);
	}
	bfs(1);
	cin >> q;
	while(q--){

	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
