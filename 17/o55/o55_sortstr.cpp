/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o55_sortstr
 * ALGO		: Sorting
 * DATE		: 8 Jan 2022
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
	string s;
	vector<string> v;
	for(int i=1; i<=n; ++i){
		cin >> s;
		v.push_back(s);
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
