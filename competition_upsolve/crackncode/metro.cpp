#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
using pii = pair<int, int>;

const int N = 5e4 + 5;
const int INF = 1e9 + 7;

int w[2 * N], dist[N * 2];
vector<int> g[N * 2];

int main() {
	int n, m, x, k;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++) {
		scanf("%d %d", &k, &w[i + n]);
		for(int j=1; j<=k; j++) {
			scanf("%d", &x);
			g[i + n].push_back(x);
			g[x].push_back(i + n);
		}
	}
	for(int i=0; i<2*N; i++) {
		dist[i] = INF;
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[0] = 0;
	pq.push(make_pair(0, 0));
	while(!pq.empty()) {
		pair<int, int> t = pq.top();
		pq.pop();
		for(int v: g[t.second]) {
			if(dist[v] > t.second + w[v]) {
				dist[v] = t.second + w[v];
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	if(dist[n-1] >= INF) {
		printf("-1\n");
	}
	else {
		printf("%d\n", dist[n-1]);
	}
	return 0;
}
