/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: IZhO14_Bank
 * ALGO		: Dynamic Programming
 * DATE		: 7 Feb 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 22;
int a[MxN], b[MxN], qs[MxN];
bitset<(1 << MxN)> dp;

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		qs[i] = qs[i - 1] + a[i];
	}
	for(int i=0; i<m; ++i){
		cin >> b[i];
	}
	dp[0] = true;
	for(int state=1; state<(1 << m); ++state){
		int sum = 0;
		for(int i=0; i<m; ++i){
			if(state & (1 << i)){
				sum += b[i];
			}
		}
		if(sum > qs[n]){
			continue;
		}
		int l = 0, r = n;
		while(l < r){
			int mid = (l + r) >> 1;
			
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
