/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o58_oct_c1_evergreen
 * ALGO		: Binary Search
 * DATE		: 31 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1010;

void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(auto &x: a){
		cin >> x;
	}
	sort(a.begin(), a.end());
	ll l = 0, r = 1e9;
	while(l < r){
		ll mid = (l + r) >> 1;
		ll cnt = (mid + 1) * (mid + 1) * n;
		for(int i=1; i<n; ++i){
			if(a[i] == a[i - 1]){
				cnt -= (mid + 1) * (mid + 1);
				continue;
			}
			ll diff = a[i] - a[i - 1] - 1;
			ll m = diff / 2;
			if(m < mid){
				ll diff2 = mid - m;
				if(diff % 2){
					cnt -= diff2 * diff2;
				}
				else{
					cnt -= diff2 * (diff2 + 1);
				}
			}
		}
		if(cnt < k){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	cout << r;
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
