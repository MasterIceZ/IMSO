/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct21_flower
 * ALGO		: Dynamic Programming
 * DATE		: 31 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 111;
int dp[MxN][MxN][MxN];

void solve(){
	int m, n, a, b, c;
	cin >> m >> n;
	int cnt_r = 0, cnt_s = 0;
	for(int i=1; i<=n; ++i){
		cin >> a >> b >> c;
		if(c == 1){
			cnt_s++;
		}
		else{
			cnt_r++;
		}
		for(int j=m; j - a>=0; --j){
			for(int r=cnt_r; r - (c == 0) >=0; --r){
				for(int s=cnt_s; s - (c == 1) >=0; --s){
					int ii = r - (c == 0);
					int jj = s - (c == 1);
					dp[j][r][s] = max(dp[j][r][s], dp[j - a][ii][jj] + b);
				}
			}
		}
	}
	int answer = 0;
	for(int x=0; x<=cnt_r; ++x){
		for(int y=0; y<cnt_s; ++y){
			if(max({0, x - 1, y - 1}) / 2 > min(x, y)){
				continue;
			}
			answer = max(answer, dp[m][x][y]);
		}
	}
	cout << answer ;
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
