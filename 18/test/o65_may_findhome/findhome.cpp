#include "findhome.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 330;
int dp[MxN][MxN];
vector<int> lift[MxN][MxN];

int find_home(int N, int M, std::vector<std::pair<int,int>> R)
{
	memset(dp, 0x3f, sizeof dp);
	for(auto x: R){
		dp[x.first + 1][x.second + 1] = 1;
		dp[x.second + 1][x.first + 1] = 1;
	}
	for(int i=1; i<=n; ++i){
		dp[i][i] = 0;
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(i == j){
				continue;
			}
			lift[dist[i][j]][i].emplace_back(j);
		}
	}
	return 0;
}
