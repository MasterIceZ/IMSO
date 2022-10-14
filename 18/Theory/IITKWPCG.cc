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

const int MxN = 1e5 + 10;
vector<Edge> edges;
int parent[MxN];

int find_root(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

void solve(){
	edges.clear();
	int n, m, u, v;
	long long w;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i){
		parent[i] = i;
	}
	for(int i=1; i<=m; ++i){
		scanf("%d %d %lld", &u, &v, &w);
		int ww = __builtin_ctzll(w);
		edges.emplace_back(u, v, ww);
	}
	sort(edges.begin(), edges.end());
	int answer = 1;
	for(auto x: edges){
		int ru = find_root(x.u);
		int rv = find_root(x.v);
		if(ru == rv){
			continue;
		}
		parent[ru] = rv;
		answer += x.w;	
	}
	printf("%d", answer);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
		printf("\n");
	}
	return 0;
}
