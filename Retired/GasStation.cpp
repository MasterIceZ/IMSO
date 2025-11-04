#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

const int MxN = 200020;

std::vector<std::pair<int, long long>> adj[MxN];
int n, k, uses;
bool good;

inline void ordered_max(long long t, long long &first_max, long long &second_max) {
	if(t >= first_max) {
		second_max = first_max;
		first_max = t;
		return ;
	}
	if(t >= second_max) {
		second_max = t;
		return ;
	}
	return ;
}

long long dfs(int u, int p, const long long &cap) {
	long long first_max = 0ll, second_max = 0ll, max_len = 0ll;
	for(auto [v, w]: adj[u]) {
		if(v == p) {
			continue;
		}
		long long t = dfs(v, u, cap) + w;
		ordered_max(t, first_max, second_max);
		max_len = w;
	}
	
	long long current = first_max + second_max;
	if(current > cap) {
		uses += 1;
		current = max_len;
	}
	
	return current;
}

inline bool ok(int mid) {
	good = true;
	uses = 0;
	dfs(1, 0, mid);
	return good && uses <= k;
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	
	std::cin >> n >> k;
	long long w, sum_w = 0ll;
	for(int i=2, u, v; i<=n; ++i) {
		std::cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		sum_w += w;
	}

	for(int i=1; i<=n; ++i) {
		std::sort(adj[i].begin(), adj[i].end(), [&](const std::pair<int, long long> &a, const std::pair<int, long long> &b) {
			return a.second < b.second;
		});
	}

	long long l = 0, r = sum_w;
	while(l < r) {
		long long mid = (l + r) >> 1ll;
		if(ok(mid)) {
			r = mid;
		}
		else {
			l = mid + 1ll;
		}
	}

	std::cout << l << "\n";

	return 0;
}
