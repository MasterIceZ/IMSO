#include <bits/stdc++.h>
#include "connection.h"

using namespace std;

const int MxN = 1000010;

vector<int> adj[MxN], component_vector[MxN];
int timer, comp_cnt, component[MxN], on_stack[MxN], idx[MxN], low[MxN];
stack<int> st;
bitset<MxN> can_go;

void tarjan(int u, int p) {
	idx[u] = low[u] = ++timer;
	on_stack[u] = true;
	st.emplace(u);
	for(auto x: adj[u]) {
		if(x == p) {
			continue;
		}
		if(idx[x] == 0) {
			tarjan(x, u);
			low[u] = min(low[u], low[x]);
		}
		else if(on_stack[x]) {
			low[u] = min(low[u], idx[x]);
		}
	}
	if(idx[u] != low[u]) {
		return ;
	}
	comp_cnt++;
	while(!st.empty() && st.top() != u) {
		on_stack[st.top()] = false;
		component[st.top()] = comp_cnt;
		st.pop();
	} 
	on_stack[u] = false;
	component[u] = comp_cnt;
	st.pop();
}

int recommended_stations(int N, int M, std::vector<int> H, std::vector<int> A, std::vector<int> B) {
	for(int i=0; i<M; ++i) {
		adj[1 + A[i]].emplace_back(1 + B[i]);
		adj[1 + B[i]].emplace_back(1 + A[i]);
	}
	
	tarjan(1, 0);
	for(int i=1; i<=N; ++i) {
		component_vector[component[i]].emplace_back(i);
	}

	can_go.set();
	for(int i=1; i<=comp_cnt; ++i) {
		int u = component_vector[i][0];
		for(int v_idx=1; v_idx<(int) component_vector[i].size(); ++v_idx) {
			int v = component_vector[i][v_idx];
			if(H[v - 1] <= H[u - 1]) {
				continue;
			}
			u = v;
		}		
		can_go[u] = false;
	}

    return MxN - can_go.count();
}
