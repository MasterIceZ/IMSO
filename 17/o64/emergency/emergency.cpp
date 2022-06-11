#include <bits/stdc++.h>
#include "emergency.h"

using namespace std;

#ifdef _DEBUG
#include "../template.hpp"
#else
#define dbg(...) 0
#endif

const int MxN = 200020;
vector<pair<int, int>> adj[MxN];
// dp[i][0] -> Maximum
// dp[i][1] -> Secondary Maximum
int dp[MxN][2]; // Transitive Max distance form Child to Parent
bool isHospital[MxN];
int dp2[MxN];

void dfs(int u, int p){
	for(auto [x, w]: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
		if(dp[x][0]){
			if(dp[x][0] + w >= dp[u][0]){
				dp[u][1] = dp[u][0];
				dp[u][0] = dp[x][0] + w;
			}
			else if(dp[x][0] + w > dp[u][1]){
				dp[u][1] = dp[x][0] + w;
			}
		}
		else if(isHospital[x]){
			if(w >= dp[u][0]){
				dp[u][1] = dp[u][0];
				dp[u][0] = w;
			}
			else if(w > dp[u][1]){
				dp[u][1] = w;
			}
		}
	}
}

void dfs2(int u, int p, int k){
	dp2[u] = max(k, dp[u][0]);
	if(adj[u].size() == 2){
		for(auto [x, w]: adj[u]){
			if(x == p){
				continue;
			}
			int nxt = 0;
			if(k != 0){
				nxt = w + k;
			}
			if(isHospital[x]){
				nxt = max(nxt, w);
			}
			dfs2(x, u, nxt);
		}
		return ;
	}
	for(auto [x, w]: adj[u]){
		if(x == p){
			continue;
		}
		int nxt = 0;
		if(k != 0){
			nxt = k + w;
		}
		if(isHospital[x]){
			nxt = max(nxt, w);
		}
		if(dp[u][0] && dp[u][1]){
			if(dp[x][0] && dp[x][0] + w == dp[u][0]){
				nxt = max(nxt, dp[u][1] + w);
			}
			else if(isHospital[x] && dp[x][0] == w){
				nxt = max(nxt, dp[u][1] + w);
			}
			else{
				nxt = max(nxt, dp[u][0] + w);
			}
		}
		else if(dp[u][0] && dp[x][0] + w != dp[u][0]){
			nxt = max(nxt, dp[x][0] + w);
		}
		dfs2(x, u, nxt);
	}
}

int furthest(int N, int H, int K, int roads[][2], int lengths[], int hospitals[], int centers[]){
	for(int i=0; i<N-1; ++i){
		adj[roads[i][0]].emplace_back(roads[i][1], lengths[i]);
		adj[roads[i][1]].emplace_back(roads[i][0], lengths[i]);
		dbg(roads[i][0], roads[i][1], lengths[i]);
	}
	for(int i=0; i<H; ++i){
		isHospital[hospitals[i]] = true;
	}
	dfs(0, -1);
	dfs2(0, -1, 0);
	int res = 0;
	for(int i=0; i<K; ++i){
		res = max(res, dp2[centers[i]]);
	}
	return res;
}

#ifdef _DEBUG

static const int MAX_N = 200010;
static int N, H, K;
static int roads[MAX_N][2];
static int lengths[MAX_N];
static int hospitals[MAX_N];
static int centers[MAX_N];

int main(){
//	freopen("sample.in", "r", stdin);
	freopen("sample_1.in", "r", stdin);
	cin >> N >> H >> K;
	for(int i=0; i<H; ++i){
		cin >> hospitals[i];
	}
	for(int i=0; i<K; ++i){
		cin >> centers[i];
	}
	for(int i=0; i<N-1; ++i){
		cin >> roads[i][0] >> roads[i][1] >> lengths[i];
	}
	cout << furthest(N, H, K, roads, lengths, hospitals, centers) << "\n";
	return 0;
}
#endif
