/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o59_oct_c1_staying
 * ALGO		: Dynamic Programming with Bitmasks, Travelling Salesman Problem
 * DATE		: 9 Oct 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int n, k[5];
vector<int> adj[5];
int dp[1010][5][1010][1 << 3];
const int MOD = 1e9 + 7;

void solve(){
	cin >> n >> k[0] >> k[1] >> k[2];
	dp[1][0][1][1] = 1;
	adj[1].push_back(0);
	adj[2].push_back(1);
	adj[0].push_back(2);
	adj[2].push_back(0);
	for(int i=2; i<=n; ++i){
		for(int state=1; state<(1 << 3); ++state){
			for(int u=0; u<3; ++u){
				// stay
				for(int j=1; j<=k[u]; ++j){
					dp[i][u][j][state | (1 << u)] += dp[i - 1][u][j - 1][state];
					dp[i][u][j][state | (1 << u)] %= MOD;
				}
				// from other
				for(auto x: adj[u]){
					for(int j=1; j<=k[x]; ++j){
						dp[i][u][1][state | (1 << u)] += dp[i - 1][x][j][state];
						dp[i][u][1][state | (1 << u)] %= MOD;
					}
				}
			}
		}
	}
	int answer = 0;
	for(int i=0; i<3; ++i){
		for(int j=1; j<=k[i]; ++j){
			answer += dp[n][i][j][7];
			answer %= MOD;
		}
	}
	cout << answer;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
