#include <bits/stdc++.h>
using namespace std ;

using ll = long long;

ll bsqrt(ll x){
	ll l = 0, r = x;
	while(l < r){
		ll mid = (l + r + 1) >> 1;
		//cerr << "D : " << l << ", " << mid << ", " << r << "\n";
		if(mid * mid == x){
			return mid;
		}
		if(mid <= x / mid){
			l = mid;
		}
		else{
			r = mid - 1ll;
		}
	}
	return l;
}

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	ll n, l, r;
	int q;
	cin >> n >> q;
	while(q--){
		cin >> l >> r;
		cout << bsqrt(r) + bsqrt(r / 2ll) - bsqrt(l - 1ll) - bsqrt((l - 1ll) / 2ll) << "\n";
	}
	return 0;
}
