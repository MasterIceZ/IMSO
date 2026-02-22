#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int MxN = 3030;

struct polynomial_t {
	long long a, b, c;
};

std::vector<int> adj[MxN];
int n, in[MxN], dp[2][MxN];
polynomial_t poly[MxN];

inline bool parabola_intersect(polynomial_t a, polynomial_t b) {
	long long delta_a = a.a - b.a;
	long long delta_b = a.b - b.b;
	long long delta_c = a.c - b.c;

	long long discriminant = delta_b * delta_b - 4 * delta_a * delta_c;
	if(delta_a == 0 && delta_b == 0) {
		return delta_c > 0;
	}
	if(discriminant < 0) {
		return delta_c > 0;
	}
	return false;
}

inline void topsort(int *dp) {
	for(int i=1; i<=n; ++i) {
		dp[i] = 1;
	}
	std::queue<int> q;
	for(int i=1; i<=n; ++i) {
		if(in[i] != 0) {
			continue;
		}
		q.emplace(i);
	}
	while(!q.empty()) {
		int u = q.front();
//		std::cerr << "X: " << u << "\n";
		q.pop();
		for(auto v: adj[u]) {
//			std::cerr << "E: " << v << "\n";
			dp[v] = std::max(dp[v], dp[u] + 1);
			if(--in[v] == 0) {
				q.emplace(v);
			}
		}
	}
}

inline void clean() {
	for(int i=1; i<=n; ++i) {
		in[i] = 0;
		adj[i].clear();
	}
}

inline void debug(int *a) {
	std::cout << "D: ";
	for(int i=1; i<=n; ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
}

void solve() {
	std::cin >> n;
	for(int i=1; i<=n; ++i) {
		std::cin >> poly[i].a >> poly[i].b >> poly[i].c;
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			if(parabola_intersect(poly[i], poly[j])) {
				adj[j].emplace_back(i);
				in[i]++;
			}
		}
	}
//	debug(in);
	topsort(dp[0]);
//	debug(dp[0]);
	clean();
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			if(parabola_intersect(poly[i], poly[j])) {
				adj[i].emplace_back(j);
				in[j]++;
			}
		}
	}
	topsort(dp[1]);
	for(int i=1; i<=n; ++i) {
		std::cout << dp[0][i] + dp[1][i] - 1 << " ";
	}
	std::cout << "\n";

	clean();
	return ;
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
