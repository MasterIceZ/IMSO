/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o56_apr20_stardrawing
 * ALGO		: Depth First Search
 * DATE		: 28 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;

vector<int> adj[MxN];
bitset<MxN> visited;
int a[MxN];

multiset<int> st;

int ptr = 0;
void dfs(int u, int p){
	if(!a[u]){
		a[u] = ++ptr;
	}
	st.emplace(a[u]);
	visited[u] = true;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		if(visited[x]){
			st.emplace(-1);
			continue;
		}
		dfs(x, u);
	}
}

void solve(){
	int n, m, u, v;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	set<multiset<int>> s;
	for(int i=1; i<=n; ++i){
		if(!visited[i] && adj[i].size() <= 1){
			ptr = 0;
			dfs(i, 0);
			s.emplace(st);
			st.clear();
		}
	}
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			ptr = 0;
			dfs(i, 0);
			s.emplace(st);
			st.clear();
		}
	}
	cout << s.size();
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
