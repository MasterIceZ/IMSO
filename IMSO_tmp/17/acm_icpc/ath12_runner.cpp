/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: ath12_runner
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


void solve(){
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> v;
	for(int i=1, vv, t; i<=n; ++i){
		cin >> vv >> t;
		v.emplace_back(t + m * 1000 / vv, -vv, i);
	}
	sort(v.begin(), v.end());
	for(auto x: v){
		cout << get<2>(x) << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
