/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: mar14_mst
 * ALGO		: Minimum Spanning Tree
 * DATE		: 28 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Edge{
	int u, v, w, idx;
	Edge(int a, int b, int c, int d) : u(a), v(b), w(c), idx(d) {}
	bool operator < (const Edge& o) const{
		if(w != o.w){
			return w > o.w;
		}
		return idx > o.idx;
	}
};

template<size_t S> struct DSU{
	array<int, S + 20> p;
	DSU(){
		p[0] = 0;
		for(int i=1; i<=(int)S; ++i){
			p[i] = i;
		}
	}
	int fr(int u){
		return p[u] == u ? u: p[u] = fr(p[u]);
	}
	void merge(int u, int v){
		p[u] = v;
	}
};

priority_queue<Edge> edges;

void solve(){
	int n, m, u, v, w;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		edges.emplace(u, v, w, i - 1);
	}
	DSU<1010> dsu;
	int answer = 0;
	vector<int> use;
	while(!edges.empty()){
		Edge now = edges.top();
		edges.pop();
		int ru = dsu.fr(now.u);
		int rv = dsu.fr(now.v);
		dbg(ru, rv);
		if(ru == rv){
			continue;
		}	
		dsu.merge(ru, rv);
		answer += now.w;
		use.push_back(now.idx);	
	}
	cout << answer << "\n";
	for(auto x: use){
		cout << x << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
