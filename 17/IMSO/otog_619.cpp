/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

vector<int> adj[1010];
bitset<1010> visited;
stack<int> st;
int comp[1010];

void dfs(int u, int p){
	visited[u] = true;
	for(auto x: adj[u]){
		if(x == p || visited[x]){
			continue;
		}
		dfs(x, u);
	}
	st.push(u);
}

void dfs2(int u, int p, int id){
	visited[u] = true;
	comp[u] = id;
	for(auto x: adj[u]){
		if(x == p || visited[x]){
			continue;
		}
		dfs2(x, u, id);
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			dfs(i, 0);
		}
	}
	visited = 0;
	int it = 0;
	while(!st.empty()){
		int now = st.top();
		st.pop();
		if(visited[now]){
			continue;
		}
		dfs2(now, 0, ++it);
	}
	cout << it;
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
