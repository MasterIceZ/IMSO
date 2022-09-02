/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Range Minimum Query
 * ALGO		: Square Root Decomposition
 * DATE		: 4 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int a[100100], cluster[333];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int sq = sqrt(n);
	memset(cluster, 0x3f, sizeof cluster);
	for(int i=1; i<=n; ++i){
		cluster[i / sq] = min(cluster[i / sq], a[i]);
	}
	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		l++, r++;
		int res = 1e9 + 10;
		for(int i=l; i<=r; ){
			if(i % sq == 0 && i + sq - 1 <= r){
				res = min(res, cluster[i / sq]);
				i += sq;
			}
			else{
				res = min(res, a[i]);
				i += 1;
			}
		}
		cout << res << "\n";
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
