/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: Chula
 * TASK		: Coiunting Graphs
 * ALGO		: Kruskal's Algorithm
 * DATE		: 12 Sep 2023
 * */

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

struct edge_t {
	int u, v;
	ll w;
	bool operator < (const edge_t& o) const {
		return w < o.w;
	}
	edge_t(int _u, int _v, ll _w):
		u(_u), v(_v), w(_w) {}
};

const ll MOD = 998244353ll;
const int MxN = 200020;

int n, p[MxN], u, v;
ll w, s, sz[MxN], answer;
vector<edge_t> edges;

int findRoot(int u) {
	while(u != p[u]) {
		u = p[u];
	}
	return u;
}

void unite(int u, int v) {
	int ru = findRoot(u), rv = findRoot(v);
	if(ru == rv) {
		return ;
	}
	if(sz[ru] > sz[rv]) {
		swap(ru, rv);
	}
	sz[rv] += sz[ru];
	p[ru] = rv;
}

ll modOfPower(ll a, ll b) {
	if(a == 1ll || b == 0ll) {
		return 1ll;
	}
	if(b == 1ll) {
		return a;
	}
	ll t = modOfPower(a, b >> 1ll);
	ll res = (t * t) % MOD;
	if(b & 1ll) {
		res = (res * a) % MOD;
	}
	return res;
}

inline void solution(){
	cin >> n >> s;
	edges.clear();
	for(int i=2; i<=n; ++i) {
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}
	sort(edges.begin(), edges.end());
	for(int i=1; i<=n; ++i) {
		p[i] = i;
		sz[i] = 1;
	}
	answer = 1ll;
	for(auto x: edges) {
		int ru = findRoot(x.u);
		int rv = findRoot(x.v);
		answer = (answer * modOfPower(s - x.w + 1ll, sz[ru] * sz[rv] - 1ll)) % MOD;
		unite(ru, rv);
	}
	cout << answer;
	dbg(answer);
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
