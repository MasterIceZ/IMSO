/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: List Removals
 * ALGO		: Rope
 * DATE		: 6 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#include<ext/rope>
using namespace __gnu_cxx;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

rope<int> rp;

void solve(){
	int n;
	cin >> n;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		rp.push_back(x);
	}
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		cout << rp[x - 1] << " " ;
		rp.erase(rp.mutable_begin() + x - 1);
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
