/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Final Crisis
 * ALGO		: Binary Search
 * DATE		: 25 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int n, m, idx;
ll qsp[100100], qsq[100100];

void solve(){
	ll a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	ll l = 0, r = 1e18;
	while(l < r){
		ll mid = (l + r) >> 1;
		idx = min(c, (ll)(upper_bound(qsp + 1, qsp + n + 1, qsp[a - 1] + mid) - (qsp + 1)));
		ll idp = idx - a + 1;
		idx = min(d, (ll)(upper_bound(qsq + 1, qsq + m + 1, qsq[b - 1] + mid) - (qsq + 1)));
		ll idq = idx - b + 1;
		if(idp + idq < k){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	cout << l;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		cin >> qsp[i];
		qsp[i] += qsp[i - 1];
	}
	for(int i=1; i<=m; ++i){
		cin >> qsq[i];
		qsq[i] += qsq[i - 1];
	}
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
