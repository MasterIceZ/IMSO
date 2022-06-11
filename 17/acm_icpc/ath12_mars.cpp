/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Mars
 * ALGO		: Dynamic Programming
 * DATE		: 28 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1010;
int dp[MxN][33][33];

inline int d(int a, int b){
	if(a > b){
		swap(a, b);
	}
	return min(b - a, a - b + 26);
}

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	memset(dp, 0x3f, sizeof dp);
	dp[0][0][0] = 0;
	for(int i=1; i<=n; ++i){
		for(int j=0; j<26; ++j){
			for(int k=0; k<26; ++k){
				dp[i][s[i] - 'A'][k] = min(dp[i][s[i] - 'A'][k], dp[i - 1][j][k] + d(s[i] - 'A', j));
				dp[i][j][s[i] - 'A'] = min(dp[i][j][s[i] - 'A'], dp[i - 1][j][k] + d(s[i] - 'A', k));
			}
		}
	}
	int answer = 1e9 + 100;
	for(int j=0; j<26; ++j){
		for(int k=0; k<26; ++k){
			answer = min(answer, dp[n][j][k]);
		}
	}
	cout << answer ;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
