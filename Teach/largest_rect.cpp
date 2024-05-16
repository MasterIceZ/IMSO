#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 3033;

ll answer, a[MxN], l[MxN], r[MxN];

signed main(int argc, char *argv[]) {
	int n;
	while(1) {
		scanf("%d", &n);
		if(n == 0) {
			break;
		}
		for(int i=1; i<=n; ++i) {
			scanf("%lld", &a[i]);
		}
		for(int i=1; i<=n; ++i) {
			l[i] = i - 1;
			while(l[i] > 0 && a[i] <= a[l[i]]) {
				l[i] = l[l[i]];
			}
		}
		answer = -1e18 - 100ll;
		for(int i=n; i>=1; --i) {
			r[i] = i + 1;
			while(r[i] <= n && a[i] <= a[r[i]]) {
				r[i] = r[r[i]];
			}
			answer = max(answer, (r[i] - l[i] - 1ll) * a[i]);
		}
		printf("%lld\n", answer);
	}
	return 0;
}
