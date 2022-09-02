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

struct Node{
	int v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
	Node(int a, int b): v(a), w(b) {}
};

const int MxN = 1 << 16;
const int MxL = 7;
vector<int> adj[2 * MxN + 10];
int level[2 * MxN + 10], dp[2 * MxN][22];
int dist[2 * MxL][2 * MxN + 10];
pair<int,int> br[2 * MxL];
priority_queue<Node> pq;

void dfs(int u, int p, int lv = 1){
	level[u] = lv;
	dp[u][0] = p;
	for(int state=1; state<=16; ++state){
		dp[u][state] = dp[dp[u][state - 1]][state - 1];
	}
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u, lv + 1);
	}
}

inline void dijkstra(int source, int state, int id){
	pq.emplace(source, 0);
	dist[state][source] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(dist[state][now.v] != now.w){
			continue;
		}
		for(auto x: adj[now.v]){
			if(make_pair(now.v, x) == br[id] || make_pair(x, now.v) == br[id]){
				continue;
			}
			int nxt = dist[state][now.v] + 1;
			if(dist[state][x] > nxt){
				pq.emplace(x, dist[state][x] = nxt);
			}
		}
	}
}

inline int lca(int u, int v){
	if(level[u] < level[v]){
		swap(u, v);
	}
	for(int state=16; state>=0; --state){
		if(level[dp[u][state]] >= level[v]){
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
	dbg(dp[u][0]);
	return dp[u][0];
}

void solve(){
	int k, l, q;
	cin >> k >> l >> q;
	int s = (1 << k);
	for(int i=1; i<(1 << (k - 1)); ++i){
		adj[i].push_back(i * 2);
		adj[i].push_back(i * 2 + 1);
		adj[i + s].push_back(i * 2 + s);
		adj[i + s].push_back(i * 2 + 1 + s); 

		adj[i * 2].push_back(i);
		adj[i * 2 + 1].push_back(i);
		adj[i * 2 + s].push_back(i + s);
		adj[i * 2 + 1 + s].push_back(i + s);
	}
	dfs(1, 0);
	int u, v;
	for(int i=1; i<=l; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		br[i] = make_pair(u, v);
	}
	memset(dist, 0x3f, sizeof dist);
	int pt = 0;
	for(int i=1; i<=l; ++i){
		dijkstra(br[i].first, pt * 2, i);
		dijkstra(br[i].second, pt * 2 + 1, i);
		pt += 1;
	}
	dbg(lca(1, 2));
	while(q--){
		int answer = 1e9 + 10;
		cin >> u >> v;
		for(int i=0; i<l; ++i){
			answer = min({answer, dist[i * 2][u] + dist[i * 2 + 1][v] + 1, dist[i * 2][v] + dist[i * 2 + 1][u] + 1});
		}
		int LCA = 0;
		if(u < s && v < s){
			LCA = lca(u, v);
			dbg(LCA);
			answer = min(answer, level[u] + level[v] - 2 * level[LCA]);
		}
		else if(u >= s && v >= s){
			LCA = lca(u - s, v - s);
			dbg(LCA);
			answer = min(answer, level[u - s] + level[v - s] - 2 * level[LCA]);
		}
		dbg(answer);
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
