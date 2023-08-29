#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

int n, m;

vector<int> adj[MxN], bcc[MxN];
int idx[MxN], low[MxN], id, b_id;
stack<int> st;
bitset<MxN> art_point;

void dfs(int u, int p) {
	idx[u] = low[u] = ++id;
	st.emplace(u);
	int cnt = 0;
	for(auto x: adj[u]) {
		if(!idx[x]) {
			dfs(x, u);
			low[u] = min(low[u], low[x]);
			cnt++;
			if(p == 0 && cnt > 1 || p != 0 && low[x] >= idx[u]) {
				art_point[u] = true;
			}
			if(low[v] >= idx[u]) {
				bct[++b_id].emplace_back(u);
				while(bct[b_id] != x) {
					
				}
			}
		}
		else if(x != p) {
			low[u] = min(low[u], idx[x]);
		}
	}
}

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for(int i=2; i<=m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	return 0;
}
