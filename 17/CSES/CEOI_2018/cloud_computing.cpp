/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: cloud computing
 * ALGO		: 
 * DATE		: 9 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 2020;

struct Com{
	ll f, c, v;
};

Com a[MxN], b[MxN];
ll dp[MxN * 50], dp2[MxN * 50];
ll answer = 0;
int n, m;

bitset<2020> choose_x;

void calc(int x, ll current){
	if(x == n){
		answer = max(answer, current);
		return ;
	}
	choose_x[x] = true;
	ll last = 0;
	for(int i=1; i<=m; ++i){
		
	}

	choose_x[x] = false;
	calc(x + 1, current);
}

void sub_4(){
	for(int i=1; i<=n; ++i){
		cin >> a[i].c >> a[i].f >> a[i].v;
	}
	int m;
	cin >> m;
	for(int i=1; i<=m; ++i){
		cin >> b[i].c >> b[i].f >> b[i].v;
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for(int i=1; i<=n; ++i){
		for(int j=50*n; j>=a[i].c; --j){
			dp[j] = min(dp[j], dp[j - a[i].c] + a[i].v);
		}
	}
	for(int i=n; i>=1; --i){
		dp[i] = min(dp[i], dp[i + 1]);
	}
	for(int i=1; i<=m; ++i){
		for(int j=50*n; j>=b[i].c; --j){
			dp2[j] = max(dp2[j], dp2[j - b[i].c] + b[i].v);
		}
	}
	ll answer = 0;
	for(int i=1; i<=50*n; ++i){
		answer = max(answer, dp2[i] - dp[i]);
	}
	cout << answer;
	return ;
}

void solve(){
	cin >> n;
	sub_4();
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
