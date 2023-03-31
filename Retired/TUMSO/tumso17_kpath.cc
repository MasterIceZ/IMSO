/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: K-Path
 * ALGO		: Centroid Decomposition
 * DATE		: 26 Mar 2023
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

const int MxN = 100010;
bitset<MxN> done;
vector<pair<int, ll>> adj[MxN];
int n, sz[MxN];
ll k, w, answer = 1e18;
set<ll> st;

int dfsSize(int u, int p){
	sz[u] = 1;
	for(auto x: adj[u]){
		if(x.first == p || done[x.first]){
			continue;
		}
		sz[u] += dfsSize(x.first, u);
	}
	return sz[u];
}

int getCentroid(int u, int n, int p){
	for(auto x: adj[u]){
		if(x.first == p || done[x.first]){
			continue;
		}
		if(sz[x.first] > n / 2){
			return getCentroid(x.first, sz[x.first], u);
		}
	}
	return u;
}

void dfs(int u, int p, bool state, ll dist){
	if(state){
		st.emplace(dist);
	}
	else{
		set<ll>::iterator it = st.upper_bound(k - dist);
		if(it != st.end()){
			answer = min(answer, abs(k - *it - dist));
		}
		if(it != st.begin()){
			--it;
			answer = min(answer, abs(k - *it - dist));
		}
	}
	for(auto x: adj[u]){
		if(x.first == p || done[x.first]){
			continue;
		}
		dfs(x.first, u, state, dist + x.second);
	}
}

void buildCentroid(int u, int p){
	int cen = getCentroid(u, dfsSize(u, 0), 0);
	dbg(u, cen);
	done[cen] = true;
	st.clear(); st.emplace(0ll);
	for(auto x: adj[u]){
		if(done[x.first]){
			continue;
		}
		dfs(x.first, cen, false, x.second);
		dfs(x.first, cen, true, x.second);
	}
	for(auto x: adj[u]){
		if(done[x.first]){
			continue;
		}
		buildCentroid(x.first, u);
	}
}

inline void solution(){
	int u, v;
	cin >> n >> k;
	for(int i=2; i<=n; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	buildCentroid(1, 0);
	cout << answer;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
