#include "magic.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;
const ll HSH = 200003;
vector<int> adj[MxN];

bitset<MxN> reach;
int w;
unordered_map<ll, bool> closed;
vector<pair<int, int>> edges;

inline ll get_idx(pair<int, int> e){
	ll a = (ll) e.first;
	ll b = (ll) e.second;
	return a * HSH + b;
}

int dfs(int u, int p, int cnt){
	reach[u] = true;
	int res = 1e9 + 100;
	if(u == w){
		return cnt;
	}
	for(auto x: adj[u]){
		if(x == p || reach[x]){
			continue;
		}
		if(closed[get_idx(make_pair(min(u, x), max(u, x)))]){
			res = min(res, dfs(x, u, cnt + 1));
		}
		else{
			res = min(res, dfs(x, u, cnt));
		}
	}
	return res;
}

vector<int> magic(int N, int M,int Q, vector<int>U, vector<int> V, vector<vector<int> >q){
	vector<int> res;
	for(int i=0; i<M; ++i){
		adj[U[i]].emplace_back(V[i]);
		adj[V[i]].emplace_back(U[i]);
		edges.emplace_back(min(U[i], V[i]), max(U[i], V[i]));
	}
	for(auto query: q){
		if(query[0] == 0){
			res.emplace_back(-1);
			closed[get_idx(edges[query[1]])] = true;
		}
		else{
			reach = 0;
			w = query[1];
			int r = dfs(0, -1, 0);
			cerr << "r : " << r << "\n";
			if(!reach[w] || r > query[2]){
				res.emplace_back(0);
			}
			else{
				res.emplace_back(1);
			}
		}
	}
	return res;
}
