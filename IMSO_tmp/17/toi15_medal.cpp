/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi15_medal
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

const int MxN = 500500;
ll answer, a[MxN], b[MxN], c[MxN];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		cin >> b[i];
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1, greater<int>());
	for(int i=1; i<=n; ++i){
		c[i] = a[i] + b[i];
	}
	sort(c + 1, c + n + 1);
	for(int i=2; i<=n; ++i){
		answer += c[i] - c[i - 1];
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
