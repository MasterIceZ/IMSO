/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: distance
 * ALGO		: Dynamic Programming, Greedy
 * DATE		: 26 Dec 2021
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
ll x[MxN], y[MxN], qsx[MxN], qsy[MxN];

void solve(){
	ll n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> x[i] >> y[i];
	}
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	ll ans = 0;
	for(int i=1; i<=n; ++i){
		qsx[i] = qsx[i - 1] + x[i];
		qsy[i] = qsy[i - 1] + y[i];
	}
	for(ll i=1; i<=n; ++i){
		ans += (qsx[n] - qsx[i]) - ((n - i) * x[i]);
		ans += (qsy[n] - qsy[i]) - ((n - i) * y[i]);
	}
	cout << ans;
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
