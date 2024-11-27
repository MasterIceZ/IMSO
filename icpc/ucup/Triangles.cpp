#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll count_tri(ll n) {
	return (n * (n + 2ll) * (2ll * n + 1ll)) / 8ll;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	ll n, r, c;
	cin >> n >> r >> c;
	ll all_tri = count_tri(n);
	ll rem_up
	cout << all_tri - rem_up << "\n";
	return 0;
}
