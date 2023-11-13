#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll bound, p[20];

inline int query(ll number) {
	int response;
	printf("query %lld\n", number);
	scanf("%d", &response);
	return response;
}

inline bool ok(ll v) {
	return query(v) <= bound;
}

signed main() {
	p[0] = 1ll;
	for(int i=1; i<18; ++i) {
		p[i] = p[i - 1] * 10ll;
	}

	ll answer = 0ll;
	bound = query(0ll);
	for(int rdx=0; rdx<18; ++rdx) {
		ll l = 1ll, r = 10ll;
		while(l < r) {
			ll mid = (l + r) >> 1ll;
			if(ok(mid * p[rdx])) {
				r = mid;
			}
			else {
				l = mid + 1ll;
			}
		}
		answer = answer * p[rdx] + (10ll - l);
	}
	printf("answer %lld\n", answer);

	return 0;
}
