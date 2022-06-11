/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: running
 * ALGO		: Greedy
 * DATE		: 10 Jan 2022
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
	int n, k;
	cin >> n >> k;
	vector<ll> a(n + 1);
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	sort(a.begin() + 1, a.begin() + n + 1);
	a[1] *= k;
	int cnt = 1;
	for(int i=2; i<=n; ++i){
		if(a[1] > a[i] * (k - 1)){
			cnt++;
		}
	}
	cout << cnt;
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
