#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

int idx[MxN], low[MxN];
vector<int> adj[MxN];
vector<vector<int>> ccs;
bitset<MxN> visited, art;

void find_component(int u, int p) {
	static int idx = 0;
	static stack<int> st;

	idx[u] = low[u] = ++idx;
	visited[u] = true;
	st.emplace(u);
	int cnt = 0;
	for(auto x: adj[u]) {
		if(visited[x]) {
			continue;
		}
		cnt++;
		find_component(x, u);
		low[u] = min(low[u], low[x]);
		if(p == 0 && cnt > 1 || p != 0 && low[x] >= idx[u]) {
			art[u] = true;
		}
		if(low[x] >= idx[u]) {
			vector<int> c;
			c.emplace_back(u);
			while(c.back() != v) {
				c.emplace_back(st.top());
				st.pop();
			}
		}
	}
}

void gen_block_cut_tree() {
	adj
}
