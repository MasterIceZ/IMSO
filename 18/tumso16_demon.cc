/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Demonic Tree
 * ALGO		: Euler Tour, Square Root Decomposition
 * DATE		: 23 Jul 2022
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

const int MxN = 2e5 + 20;

struct FenwickTree{
	ll tree[MxN * 2];
	void update(int idx, ll val){
		for(; idx<=400000; idx+=idx&-idx){
			tree[idx] += val;
		}
	}
	ll read(int idx){
		ll res = 0ll;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} fw;

vector<int> adj[MxN];
ll pw[MxN], answer[MxN];
int in[MxN], out[MxN], timer;

void dfs(int u, int p){
	in[u] = ++timer;
	for(auto x: adj[u]){
		dfs(x, u);
	}
	out[u] = ++timer;
}

inline void solution(){
	int n, q;
	cin >> n >> q;
	for(int i=2, x; i<=n; ++i){
		cin >> x;
		adj[x].emplace_back(i);
	}
	for(int i=1; i<=n; ++i){
		cin >> pw[i];
	}
	dfs(1, 0);
	for(int i=1; i<=n; ++i){
		dbg(in[i], out[i]);
		fw.update(in[i], pw[i]);
		fw.update(out[i] + 1, -pw[i]);
	}
	dbg(fw.read(out[1]));
	for(int i=1; i<=n; ++i){
		answer[i] = fw.read(out[i]) - fw.read(in[i] - 1);
	}
	for(int i=1, x; i<=q; ++i){
		cin >> x;
		cout << answer[x] << "\n";
	}
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
