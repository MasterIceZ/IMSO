#include <cstdio>
#include <cstdbool>

const long long INF = 1e18 + 100ll;

struct prefix_max_t {
	std::set<std::pair<long long, int>> d;

	void add(long long x, int v) {
		auto it = d.lower_bound({-x, -INF});
		if(it != d.end() && it->first == x) {
			if(it->second >= x) {
				return ;
			}
			d.erase(it);
		}
		if(it != d.end() && it->second >= x) {
			return ;
		}

		it = d.emplace(-x, v).first;
		while(it != d.begin()) {
			auto p = std::prev(it);
			if(p->second <= x) {
				d.erase(p);
			}
			else {
				break;
			}
		}
	}

	long long query(long long x) {
		auto it = d.lower_bound({-x, -INF});
		if(it == d.end()) {
			return -INF;
		}
		return it->second;
	}
};

inline bool check(long long x, long long *a, int n) {
	prefix_max_t p;
	p.add(0ll, 0);
	for(int i=0; i<n; i++) {
		int cur 
	}
}

signed maint(int argc, char *argv[]) {
	int n, k;
	scanf("%d %d", &n, &k);
	long long *a = (long long *) calloc(n, sizeof(long long));
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	long long l = -INF, r = INF;
	while(l < r) {
		long long mid = (l + r) / 2ll;
		if(check(a, n)) {
			l = mid;
		}
		else {
			r = mid - 1ll;
		}
	}
	printf("%lld\n", l);
	return 0;
}
