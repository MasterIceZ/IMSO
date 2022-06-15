/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o62_mar_c2_blind ballot
 * ALGO		: Strongly Connected Component, Kosaraju's Algorithm
 * DATE		: 11 June 2022
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

const int MxN = 20020;

class Kosaraju{
private:
	vector<int> adj[MxN], rev[MxN];
	int n;
	stack<int> st;
	bitset<MxN> visited;
	vector<int> v;
	void dfs(int u, int p){
		visited[u] = true;
		for(auto x: adj[u]){
			if(x == p || visited[x]){
				continue;
			}
			dfs(x, u);
		}
		st.emplace(u);
	}
	void dfs2(int u, int p){
		visited[u] = true;
		v.emplace_back(u);
		for(auto x: rev[u]){
			if(x == p || visited[x]){
				continue;
			}
			dfs2(x, u);
		}
	}
public:
	inline void init(int _n){
		n = _n;
	}
	inline void add_edge(int a, int b){
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	inline vector<vector<int>> calc(){
		visited = 0;
		for(int i=1; i<=n; ++i){
			if(!visited[i]){
				dfs(i, 0);
			}
		}
		visited = 0;
		int it = 0;
		vector<vector<int>> answer;
		while(!st.empty()){
			int now = st.top(); st.pop();
			if(visited[now]){
				continue;
			}
			v.clear();
			dfs2(now, 0);
			answer.emplace_back(v);
		}
		return answer;
	}
} scc;

inline void solution(){
	int n, m, t, a, b, c;
	cin >> n >> m;
	scc.init(n);
	for(int i=1; i<=m; ++i){
		cin >> t >> a >> b >> c;
		if(t == 1){
			scc.add_edge(b, a);
			scc.add_edge(c, a);
		}
		else if(t == 2){
			scc.add_edge(a, b);
			scc.add_edge(a, c);
		}
		else{
			scc.add_edge(a, b);
			scc.add_edge(b, c);
			scc.add_edge(c, a);
		}
	}
	vector<vector<int>> answer = scc.calc();
	cout << answer.size() << "\n";
	for(int i=answer.size() - 1; i>=0; --i){
		sort(answer[i].begin(), answer[i].end());
		cout << answer[i].size();
		for(auto x: answer[i]){
			cout << " " << x;
		}
		cout << "\n";
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
