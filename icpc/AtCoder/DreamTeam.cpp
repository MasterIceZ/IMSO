#include <bits/stdc++.h>
#include <atcoder/mincostflow.hpp>

using namespace std;
using ll = long long;

const int MxN = 330;

ll c, max_cost[MxN][MxN], answer[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	atcoder::mcf_graph<int, ll> flow_graph(300 + 2);
	for(int i=1, a, b; i<=n; ++i) {
		cin >> a >> b >> c;
		max_cost[a][b] = max(max_cost[a][b], c);
	}
	int source = 0, sink = 301;
	for(int i=1; i<=150; ++i) {
		flow_graph.add_edge(0, i, 1, 0);
		flow_graph.add_edge(150 + i, sink, 1, 0);
		for(int j=151; j<=300; ++j) {
			if(max_cost[i][j - 150] <= 0) {
				continue;
			}
			flow_graph.add_edge(i, j, 1, (ll) 1e9 - max_cost[i][j - 150]);
		}
	}
	vector<pair<int, ll>> flow = flow_graph.slope(source, sink);
	int maxx = 0;
	for(int i=1; i<(int) flow.size(); ++i) {
		int u = flow[i - 1].first, v = flow[i].first;
		ll cost_u = flow[i - 1].second, cost_v = flow[i].second;
		ll cost = (cost_v - cost_u) / (v - u);
		for(int j=u; j<=v; ++j) {
			answer[j] = (ll) 1e9 * j - (cost_u + cost * (j - u));
		}
		maxx = v;
	}
	cout << maxx << "\n";
	for(int i=1; i<=maxx; ++i) {
		cout << answer[i] << "\n";
	}
	return 0;
}
