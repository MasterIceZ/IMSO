#include <algorithm>
#include <cstdio>
#include <vector>

long long x;
std::vector<long long> lis;

signed main(int argc, char *argv[]) {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i) {
		scanf("%lld", &x);
		x = m * i - x;
		
		if(x < 0ll) {
			continue ;
		}
		auto it = std::upper_bound(lis.begin(), lis.end(), x);
		if(it == lis.end()) {
			lis.emplace_back(x);
		}
		else {
			*it = x;
		}
	}

	printf("%d", n - (int) lis.size());
	return 0;
}
