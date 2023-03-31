#include <bits/stdc++.h>
using namespace std;

const int Max_N = 5e4 + 10;
const int Max_K = 20 + 1; 

struct GRAPH {
	int u;
	long long w;
	int state;
	bool operator < (const GRAPH &o) const {
		return w > o.w;
	}
};

vector <GRAPH> adj[Max_N];
long long dis[Max_K][Max_N];
priority_queue <GRAPH> pq;
bool isSpecial[Max_N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, m, p, k;
	cin >> n >> m >> p >> k;
	for(int i = 1; i <= m; i++) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	for(int i = 1; i <= p; i++) {
		int u;
		cin >> u;
		isSpecial[u] = true;
	}
	for(int state = 0; state <= 20; state++) {
		for(int i = 1; i <= n; i++) {
			dis[state][i] = 1e18;
		}
	}
	int s;
	cin >> s;
	dis[0][s] = 0;
	pq.push({s, 0, 0});
	while(!pq.empty()) {
		int u = pq.top().u;
		long long w = pq.top().w;
		int state = pq.top().state;
		pq.pop();
		if(u == s && state == k) {
			cout << dis[state][u] << '\n';
			return 0;
		}
		for(auto x : adj[u]) {
			int next_w = dis[state][u] + x.w;
			if(isSpecial[x.u] && state + 1 <= k) {	
				int next_state = state + 1;
				if(dis[next_state][x.u] <= next_w)
					continue;
				dis[next_state][x.u] = next_w;
				pq.push({x.u, next_w, next_state});
			}
			int next_state = state;
			if(dis[next_state][x.u] <= next_w)
				continue;
			dis[next_state][x.u] = next_w;
			pq.push({x.u, next_w, next_state});
		}
	}
	cout << "NO FOOD :(" << '\n';
	return 0;
}
