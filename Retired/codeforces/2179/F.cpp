#include <iostream>
#include <queue>
#include <string>

const char *COLORS = "rgb";

inline void agent_play() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> adj(n);
	for(int i=1, u, v; i<=m; ++i) {
		std::cin >> u >> v;
		adj[--u].emplace_back(--v);
		adj[v].emplace_back(u);
	}
	std::vector<int> dist(n, -1);
	std::queue<int> q;
	dist[0] = 0;
	q.emplace(0);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v: adj[u]) {
			if(dist[v] != -1) {
				continue;
			}
			dist[v] = dist[u] + 1;
			q.emplace(v);
		}
	}
	for(int i=0; i<n; ++i) {
		std::cout << COLORS[dist[i] % 3];
	}
	std::cout << "\n";
}

inline void blackslex_play() {
	int t, d;
	std::cin >> t;
	while(t--) {
		std::string s;
		std::cin >> d >> s;
		if((int) std::set<char> (s.begin(), s.end()) == 1) {
			std::cout << 1;
		}
		else {
			std::vector<int> last(3, -1);
			for(int i=0; i<d; ++i) {
				switch(s[i]) {
					case 'r':
						last[0] = i;
					case 'g':
						last[1] = i;
					case 'b':
						last[2] = i;
				}
			}
			int cur = 3;
			for(int i=0; i<3; ++i) {
				cur -= (last[i] != 1 ? i : 0);
			}
			std::cout << COLOR[cur - 
		}
		std::cout << "\n";
	}	
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(fasle);
	std::string query_type, t;
	std::cin >> query_type >> t;
	while(t--) {
		if(query_type == "first") {
			agent_play();
		}
		else {
			blackslex_play();
		}
	}
	return 0;
}
