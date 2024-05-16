#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

ll s[MxN], e[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> s[i] >> e[i];
	}
	for(int r=n, l=n; r>=1; ) {
		if(l == 0) {
			cout << "impossible\n";
			return 0;
		}
		ll t = s[r] - (e[r] - s[r] + 1ll) / 2ll;
		while(e[l - 1] > t) {
			--l;
		}
		
	}
}
