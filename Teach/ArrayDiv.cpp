#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

ll a[MxN];

bool ok(ll mid) {

}

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	ll l = *max_element(a + 1, a + n + 1);
	ll r = accumulate(a + 1, a + n + 1, 0ll);
	while(l < r) {
		ll mid = (l + r) >> 1;
		if(ok(mid)) {
			r = mid;
		}
		else {
			l = mid + 1ll;
		}
	}
	return 0;
}
