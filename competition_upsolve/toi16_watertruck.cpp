#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 50050; 

struct edge_t {
	int u, v, w;
	edge_t(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
};

vector<edge_t> edges;
bitset<MxN> on_stack;
stack<int> st;
int idx[MxN], low[MxN], comp[MxN], it = 0, comp_cnt = 0;

void dfs_tarjan(int u, int p) {
	idx[u] = low[u] = ++it;
	on_stack[u] = true;
	st.emplace(u);
	for(auto x: adj[u]) {
		if(idx[x.first] == 0) {
			dfs_tarjan(x.first, u);
			low[u] = min(low[u], low[x.first]);
		}
		else if(on_stack[x.first]) {
			low[u] = min(low[u], idx[x.first]);
		}
	}
	if(idx[u] == low[u]) {
		return ;
	}
	++comp_cnt;
	while(!st.empty() && st.top() != u) {
		int x = st.top(); st.pop();
		on_stack[x] = false;
		comp[x] = comp_cnt;
	}
	on_stack[u] = false;
	comp[u] = comp_cnt;
	st.pop();
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  for(int i=1, u, v, w; i<=m; ++i) {
    cin >> u >> v >> w;
	u++, v++;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
	edges.emplace_back(u, v, w);
  }
  dfs_tarjan(1, 0);
	
  return 0;
}
