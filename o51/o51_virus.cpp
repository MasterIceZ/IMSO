/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o51_virus
 * ALGO		: Greedy
 * DATE		: 28 Jan 2022
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
	vector<int> a(n), b(n);
	for(auto &x: a){
		cin >> x;
	}
	for(auto &x: b){
		cin >> x;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	int answer = 0;
	for(int i=0; i<n; ++i){
		answer += b[i] - a[i];
	}
	cout << answer; 
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
