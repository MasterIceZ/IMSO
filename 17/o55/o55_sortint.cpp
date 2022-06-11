/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o55_sortint
 * ALGO		: Sorting
 * DATE		: 1 Feb 2022
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
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &x: v){
		cin >> x;
	}
	sort(v.begin(), v.end());
	for(auto x: v){
		cout << x << "\n";
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
