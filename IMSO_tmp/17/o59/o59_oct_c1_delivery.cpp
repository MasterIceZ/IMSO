/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: travel
 * ALGO		: Lowest Common Ancestor
 * DATE		: 30 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int K;
const int MxN = (1 << 16) + 20;
const int MxL = 6;

int dp[2 * MxN][22], hei[2 * MxN], bridges[2 * MxL];
int dist[2 * MxL][2 * MxL];

struct Graph{
	vector<int> adj[2 * MxN];
	void add_uedge(int l, int r){
		adj[l].push_back(r);
		adj[r].push_back(l);
	}
	void add_edge(int l, int r){
		adj[l].push_back(r);
	}
	inline void lift(int u){
		for(int state=1; state<=16; ++state){
			dp[u][state] = dp[dp[u][state - 1]][state - 1];
		}
	}
	void dfs(int u, int p){
		dbg(u, p);
		dp[u][0] = p;
		hei[u] = hei[p] + 1;
		lift(u);
		for(auto x: adj[u]){
			if(x == p){
				continue;
			}	
			dfs(x, u);
		}
	}
	int lca(int u, int v){
		if(hei[u] < hei[v]){
			swap(u, v);
		}
		for(int state=16; state>=0; --state){
			if(hei[dp[u][state]] >= hei[v]){
				u = dp[u][state];
			}
		}
		if(u == v){
			return u;
		}
		for(int state=16; state>=0; --state){
			if(dp[u][state] != dp[v][state]){
				u = dp[u][state];
				v = dp[v][state];
			}
		}
		return dp[u][0];
	}
} g;

void solve(){
	int k, l, q, u, v, pt = 0;
	cin >> k >> l >> q;
	K = (1 << k);
	// Add Bridges
	for(int i=1; i<=l; ++i){
		cin >> u >> v;
		g.add_uedge(u, v);
		bridges[++pt] = u;
		bridges[++pt] = v;
	}
	// Generate Binary Tree
	for(int i=1; i<K; ++i){
		if(i != 1){
			g.add_edge(i, i / 2);
			g.add_edge(i + K, i / 2 + K);
		}
		if(i * 2 < K){
			g.add_edge(i, i * 2);
			g.add_edge(i, i * 2 + 1);
			g.add_edge(i + K, i * 2 + K);
			g.add_edge(i + K, i * 2 + 1 + K);
		}
	}
	// Create Height && Lift
	g.dfs(1, 0);
	g.dfs(1 + K, 0);
	dbg("OK");
	for(int i=0; i<=2*l; i+=2){
		dist[i][i] = dist[i + 1][i + 1] = 0;
		for(int j=i+2; j<=2*l; j+=2){
			int u = bridges[i], v = bridges[j];
			int lca = g.lca(u, v);
			int nxt = hei[u] + hei[v] - 2 * hei[lca];
			dist[u][v] = dist[v][u] = nxt;
			u = bridges[i + 1], v = bridges[j + 1];
			lca = g.lca(u, v);
			nxt = hei[u] + hei[v] - 2 * hei[lca];
			dist[u][v] = dist[v][u] = nxt;
		}
	}
	for(int k=1; k<=2*l; ++k){
		for(int i=1; i<=2*l; ++i){
			for(int j=1; j<=2*l; ++j){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	while(q--){
		cin >> u >> v;
		if(u > v){
			swap(u, v);
		}
		int answer = 1e9 + 100;
		if((u <= K && v <= K) || (u >= K && v >= K)){
			answer = min(answer, hei[u] + hei[v] - 2 * hei[g.lca(u, v)]);
		}
		int offset_u = (u >= K);
		int offset_v = (v >= K);
		for(int i=1; i<=2*l; i+=2){
			for(int j=1; j<=2*l; j+=2){
				int br_u = bridges[i + offset_u];
				int br_v = bridges[j + offset_v];
				int nxt = hei[u] + hei[br_u] - 2 * hei[g.lca(u, br_u)];
				nxt += dist[br_u][br_v];
				nxt += hei[v] + hei[br_v] - 2 * hei[g.lca(v, br_v)];
				answer = min(answer, nxt);
			}
		}
		cout << answer << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
