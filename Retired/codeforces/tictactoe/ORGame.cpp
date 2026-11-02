#include <iostream>
#include <vector>

inline void solve() {
	int n, k;
	long long x;
	std::cin >> n >> k >> x;
	std::vector<long long> a(n + 1), p(n + 1), s(n + 1);
	for(int i=1; i<=n; ++i) {
		std::cin >> a[i];
		p[i] = p[i - 1] | a[i];
	}
	s[n] = a[n];
	for(int i=n-1; i>=1; --i) {
		s[i] = a[i] | s[i + 1];
	}
	long long xpk = 1ll;
	while(k--) {
		xpk *= x;
	}
	long long answer = 0ll;
	for(int i=1; i<=n; ++i) {
		long long cur = (xpk * a[i]) | p[i - 1] | (i == n ? 0ll : s[i + 1]);
		answer = std::max(answer, cur);
	}
	std::cout << answer << "\n";
	return ;
}

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int t = 1;
//	std::cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
