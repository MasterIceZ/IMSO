#include <iostream>

using namespace std;
using ll = long long;

const int MxN = 200020;

ll x, sum[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q, l, r;
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> x;
		sum[i] = sum[i - 1] + x;
	}
	while(q--) {
		cin >> l >> r;
		cout << sum[r] - sum[l - 1] << "\n";
	}
}
