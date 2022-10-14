#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const {
		return w < o.w;
	}
	Edge(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
};

const int MxN = 200020;
vector<Edge> edges;
int parent[MxN];

int find_root(int u){
	if(parent[u] == u){
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	while(1){
		edges.clear();
		int n, m, _;
		cin >> n >> m;
		if(n == 0 && m == 0){
			exit(0);
		}
		int sum = 0;
		for(int i=1; i<=n; ++i){
			parent[i] = i;
		}
		for(int i=1, u, v, w; i<=m; ++i){
			cin >> u >> v >> w;
			u++, v++;
			edges.emplace_back(u, v, w);
			sum += w;
		}
		sort(edges.begin(), edges.end());
		int answer = 0;
		for(auto x: edges){
			int ru = find_root(x.u);
			int rv = find_root(x.v);
			if(ru == rv){
				continue;
			}
			parent[ru] = rv;
			answer += x.w;
		}
		cout << sum - answer << "\n";
}
	return 0;
}
