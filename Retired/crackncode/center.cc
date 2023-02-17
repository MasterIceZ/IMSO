#include <bits/stdc++.h>

using namespace std;

const int MxN = 300030;
vector<int> adj[MxN];
int u[MxN], v[MxN], in[MxN];
bitset<MxN> visited;

void dfs(int u, int p){
	visited[u] = true;
	for(auto x: adj[u]){
		if(visited[x] || p == x){
			continue;
		}
		dfs(x, u);
	}
}

inline void add_edge(int mid){
	for(int i=1; i<=mid; ++i){
		adj[u[i]].emplace_back(v[i]);
		in[v[i]]++;
	}
}

inline void roll_back(int mid){
	for(int i=1; i<=mid; ++i){
		adj[u[i]].pop_back();
		in[v[i]]--;
	}
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, d, t;
	cin >> n >> m >> t >> d;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		in[v]++;
	}
	for(int i=1; i<=t; ++i){
		cin >> u[i] >> v[i];
	}
	int l = 0, r = t;
	while(l < r){
		int mid = (l + r) >> 1;
		add_edge(mid);	
		visited = 0;
		int cnt = 0;
		for(int i=1; i<=n; ++i){
			if(in[i]){
				continue;
			}
			cnt++;
			dfs(i, 0);
		}
		for(int i=1; i<=n; ++i){
			if(visited[i]){
				continue;
			}
			cnt++;
			dfs(i, 0);
		}
		if(cnt <= d + 1){
			r = mid;
		}
		else{
			l = mid + 1;
		}
		roll_back(mid);
	}
	add_edge(r);	
	visited = 0;
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		if(in[i]){
			continue;
		}
		cnt++;
		dfs(i, 0);
	}
	for(int i=1; i<=n; ++i){
		if(visited[i]){
			continue;
		}
		cnt++;
		dfs(i, 0);
	}
	cout << (cnt <= d + 1 ? l: -1);
	return 0;
}
