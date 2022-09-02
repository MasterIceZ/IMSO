/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: COI_Road Cube
 * ALGO		: Sliding Windows
 * DATE		: 10 Feb 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 10010;
const int MxM = 101;
int dp[MxN][MxM], a[MxN][MxM];

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=m; ++i){
		dp[1][i] = a[1][i];
	}
	deque<pair<int, int>> dq;
	for(int i=1; i<n; ++i){
		for(int j=1; j<=m; ++j){
			while(!dq.empty() && dq.back().first < dp[i][j]){
				dq.pop_back();
			}
			while(!dq.empty() && dq.front().second < j - (k * 2)){
				dq.pop_front();
			}
			dq.emplace_back(dp[i][j], j);
			if(j <= k){
				continue;
			}
			dp[i + 1][j - k] += dq.front().first + a[i + 1][j - k];
		}
	}	
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
