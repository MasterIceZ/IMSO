/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

char a[11][11];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
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
