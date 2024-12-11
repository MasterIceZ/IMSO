#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;
const int MxM = 220;
const int INF = 1e9 + 100;

struct MCMF {
	struct edge_t {
		int to, flow, cap, cost;
	
		edge_t(int _to, int _cap, int _cost):
			to(_to), flow(0), cap(_cap), cost(_cost) {}
		int remain() {
			return cap - flow;
		}
	};
	struct state_t {
		int v, w;
		
		state_t(int _v, int _w):
			v(_v), w(_w) {}
		bool operator < (const state_t& o) const {
			return w > o.w;
		}
	};
	
	int n, source, sink;
	vector<edge_t> edges;
	vector<int> adj[MxN];
	int sum_cost[MxN], dist[MxN], up[MxN];
	bool have_negative_edge = false;
	
	MCMF(int _source, int _sink, int _n):
		source(_source), sink(_sink), n(_n) {}
	void add_edge(int u, int v, int cap, int cost) {
		adj[u].emplace_back((int) edges.size());
		edges.emplace_back(v, cap, cost);
		adj[v].emplace_back((int) edges.size());
		edges.emplace_back(u, 0, -cost);
		if(cost < 0) {
			have_negative_edge = true;
		}
	}
	bool spfa() {
		for(int i=1; i<=n; ++i) {
			dist[i] = INF;
			up[i] = -1;
		}
		priority_queue<state_t> pq;
		pq.emplace(source, dist[source] = 0);
		while(!pq.empty()) {
			state_t cur = pq.top();
			pq.pop();
			if(dist[cur.v] != cur.w) {
				continue;
			}
			for(auto i: adj[cur.v]) {
				int v = edges[i].to;
				int next_dist = cur.w + sum_cost[cur.v] - sum_cost[v] + edges[i].cost;
				if(edges[i].remain() > 0 && dist[v] > next_dist) {
					up[v] = i;
					pq.emplace(v, dist[v] = next_dist);
				}
			}
		}
		return dist[sink] < INF;
	}
	pair<int, int> calculate() {
		for(int i=1; i<=n; ++i) {
			sum_cost[i] = 0;
		}
		int res_flow = 0, res_cost = 0;
		/*
		if(have_negative_edge) {
			cerr << "== RELAXING ==\n";
			for(int epoch=1; epoch<=n; ++epoch) {
				for(int i=0; i<(int) edges.size(); ++i) {
					if(edges[i].remain() > 0) {
						int u = edges[i ^ 1].to, v = edges[i].to;
						sum_cost[v] = min(sum_cost[v], sum_cost[u] + edges[i].cost);
					}
				}
			}
		}
		*/
		while(spfa()) {
			for(int i=1; i<=n; ++i) {
				sum_cost[i] += dist[i];
			}
			int augmenting = INF;
			for(int u=sink; u!=source; u=edges[up[u] ^ 1].to) {
				augmenting = min(augmenting, edges[up[u]].remain());
			}
			for(int u=sink; u!=source; u=edges[up[u] ^ 1].to) {
				edges[up[u]].flow += augmenting;
				edges[up[u] ^ 1].flow -= augmenting;
			}
			res_flow += augmenting;
			res_cost += augmenting + sum_cost[sink];
		}
		return make_pair(res_flow, res_cost);
	}
};

int mat[MxN], flag[MxM], tar[MxN];
vector<int> checking;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int source = 1, sink = n;
	MCMF flow(source, sink, n);
	for(int i=1, u, v, c, w; i<=m; ++i) {
		cin >> u >> v >> c >> w;
		if(c & 1) {
			c--;
			mat[u]++;
			mat[v]--;
			flag[i] = 1;
		}
		flow.add_edge(u, v, c / 2, w);
		tar[i] = (int) flow.edges.size() - 1;
	}
	for(int i=2; i<n; ++i) {
		if(mat[i] & 1) {
			cout << "Impossible\n";
			return 0;
		}
		if(mat[i] < 0) {
			flow.add_edge(source, i, -mat[i] / 2, -INF);
		}
		else {
			flow.add_edge(i, sink, mat[i] / 2, -INF);
		}
		checking.emplace_back((int) flow.edges.size() - 2);
	}
	flow.calculate();
	for(auto id: checking) {
		cerr << "! " << flow.edges[id].flow << "\n";
		if(flow.edges[id].flow != 0) {
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << "Possible\n";
	for(int i=1; i<=m; ++i) {
		cout << flow.edges[tar[i]].flow * 2 + flag[i] << " ";
	}
	cout << "\n";
	return 0;
}
