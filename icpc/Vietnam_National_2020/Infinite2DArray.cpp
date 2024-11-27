#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;
const ll MOD = 1e9 + 7ll;

ll fibo[MxN], fac[MxN], inv_fac[MxN];

inline ll add(ll a, ll b) {
	return (a + b) % MOD;
}

inline ll mul(ll a, ll b) {
	a = a % MOD;
	b = b % MOD;
	return (a * b) % MOD;
}

inline ll mop(ll a, ll b) {
	ll res = 1ll;
	for(; b>1ll; b>>=1ll, a=mul(a, a)) {
		if(b & 1ll) {
			res = mul(res, a);
		}
	}
	return res;
}

inline ll C(int n, int r) {
	if(n < r || r < 0) {
		return 0ll;
	}
	return mul(mul(fac[n], inv_fac[n - r]), inv_fac[r]);
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	fibo[0] = 0;
	fibo[1] = 1;
	for(int i=2; i<MxN; ++i) {
		fibo[i] = add(fibo[i - 1], fibo[i - 2]);
	}
	fac[0] = 1ll;
	for(int i=1; i<MxN; ++i) {
		fac[i] = mul(fac[i - 1], i);
	}
	inv_fac[MxN-1] = mop(fac[MxN - 1], MOD - 2ll);
	for(int i=MxN-2; i>=0; --i) {
		inv_fac[i] = mop(fac[i], MOD - 2ll);
	}
	int r, c;
	cin >> r >> c;
	ll res = 0ll;
	for(int p=1; p<=max(r, c); ++p) {
		ll to_add = mul(fibo[p], add(C(r + c - p - 1, c - 1), C(r + c - p - 1, c - p)));
		cerr << "D: " << fibo[p] << " " << to_add << "\n";
		res = add(res, to_add);
	}
	cout << res << "\n";
	return 0;
}
