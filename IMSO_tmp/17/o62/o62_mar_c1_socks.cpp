/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Socks Pairing
 * ALGO		: Implementation
 * DATE		: 18 Jan 2022
 * */
#include<bits/stdc++.h>

#include "sockslib.h"

using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

bitset<2020> used;

void solve(){
	int n = num();
	int N = n << 1;
	for(int i=1; i<=N; ++i){
		for(int j=i+1; j<=N; ++j){
			if(used[i] || used[j]){
				continue;
			}
			int a = ask({i, j});
			if(a == 1){
				used[i] = 1;
				used[j] = 1;
				match(i, j);
				break;
			}
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
//		cout << "\n";
	}
	return 0;
}
