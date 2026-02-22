#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

inline void solve() {
	int n, k;
	std::cin >> n >> k;
	std::queue<std::pair<int, int>> q;
	std::map<int, bool> done;
	q.emplace(n, 0);
	while(!q.empty()) {
		std::pair<int, int> cur = q.front();
		q.pop();
		if(cur.first == k) {
			std::cout << cur.second << "\n";
			return ;
		}
		if(done[cur.first]) {
			continue;
		}
		done[cur.first] = true;
		int a = cur.first / 2, b = cur.first - a;
		q.emplace(a, cur.second + 1);
		q.emplace(b, cur.second + 1);
	}
	std::cout << "-1\n";
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
