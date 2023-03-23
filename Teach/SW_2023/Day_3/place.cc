#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int u, v;
	long long w;
	bool operator < (const Edge& o) const {
		return w > o.w;
	}
	Edge(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
};
const int MxN = 200020;
vector<Edge> edges;
int parent[MxN];

int find_root(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

int main(){
	int n, m, u, v;
	long long w;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; ++i){
		scanf("%d %d %lld", &u, &v, &w);
		edges.emplace_back(u, v, w - 1);
	}
	for(int i=1; i<=n; ++i){
		parent[i] = i;
	}
	sort(edges.begin(), edges.end());
	long long sum = 0ll;
	for(auto x: edges){
		int ru = find_root(x.u), rv = find_root(x.v);
		if(ru == rv){
			continue;
		}
		sum += x.w;
		parent[ru] = rv;
	}
	printf("%lld\n", sum);
	return 0;
}
