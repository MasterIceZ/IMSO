#include "magic.h"
#include <vector>
using namespace std;

int dp[MxN];

void dfs(int u, int p){
	for(auto x: adj[u]){
	}
}

vector<int> magic(int N, int M,int Q, vector<int>U, vector<int> V, vector<vector<int> >q){
	for(int i=1; i<=M; ++i){
		adj[U[i - 1]].emplace_back(V[i - 1]);
		adj[V[i - 1]].emplace_back(U[i - 1]);
	}
	reverse(q.begin(), q.end());
	for(auto query: q){
		if(q[0] == 0){
			answer.emplace_back(-1);
	}
	
}
