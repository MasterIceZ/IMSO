#include <bits/stdc++.h>
using namespace std ;

const int MxN = 100010;
vector<int> answer, adj[222];
bitset<222> visited;
int p[MxN];

void dfs(int u, int state){
	if(u == 2 && visited[2]){
		int s = 0;
		for(int i=0; i<state; ++i){
			s *= 10;
			s += p[i];
		}
		answer.emplace_back(s);
		return ;
	}
	p[state] = u;
	if(visited[u]){
		return ;
	}
	visited[u] = true;
	for(auto x: adj[u]){
		dfs(x, state + 1);
	}
	visited[u] = false;
}

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n; 
	cin >> n;
	for(int i=1, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(2, 0);
	sort(answer.begin(), answer.end());
	for(auto x: answer){
		cout << x << "2\n";
	}
	return 0;
}
