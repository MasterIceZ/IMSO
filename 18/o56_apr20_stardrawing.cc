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
using pms = pair<int, multiset<int>>;

const int MxN = 100010;
vector<int> adj[MxN];
bitset<MxN> visited;
set<pms> answer;

void dfs(int u, int p, pms &cur, int cnt){
	visited[u] = true;
	cur.first++;
	if(adj[u].size() == 3){
		cur.second.emplace(cnt);
		cnt = -1;
	}
	cnt++;
	if(adj[u].size() == 1){
		cur.second.emplace(cnt);
	}
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		if(visited[x]){
			cur.second.emplace(-1);
			return ;
		}
		dfs(x, u, cur, cnt);
	}
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for(int i=1; i<=n; ++i){
		if(!visited[i] && adj[i].size() <= 1){
			pms cur;
			cur.first = 0;
			dfs(i, 0, cur, 0);
			answer.emplace(cur);
		}
	}
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			pms cur;
			cur.first = 0;
			dfs(i, 0, cur, 0);
			answer.emplace(cur);
		}
	}
	cout << answer.size();
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
