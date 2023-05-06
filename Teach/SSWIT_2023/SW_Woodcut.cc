#include <bits/stdc++.h>
using namespace std ;

using ll = long long;

const int MxN = 1000010;
ll a[MxN], m;
int n;

inline bool ok(ll mid){
	ll res = 0;
	for(int i=1; i<=n; ++i){
		res += max(0ll, a[i] - mid);
	}
	return res >= m;
}

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	ll l = 0, r = 1e9 + 100;
	while(l < r){
		ll mid = (l + r + 1) >> 1;
		if(ok(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << l;
	return 0;
}
