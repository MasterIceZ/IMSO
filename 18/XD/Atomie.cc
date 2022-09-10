/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Atomie
 * ALGO		: Euler Tour, Fenwick Tree
 * DATE		: 7 Sep 2022
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

template<typename T>
class fenwick_tree{
protected:
	unsigned int offset = 1024;
private:
	unsigned int sz;
	T *tree;
public:
	fenwick_tree(unsigned int _sz){
		sz = _sz + offset;
		tree = (T*) calloc(sz + offset, sizeof(T));
		assert(tree);
	}
	inline T read(unsigned int idx){
		T res = 0;
		for(; idx; idx-=idx&-idx){
			res = (res + tree[idx]);
		}
		return res;
	}
	inline void update(unsigned int idx, T value){
		for(; idx<=sz; idx+=idx&-idx){
			tree[idx] = (tree[idx] + value);
		}
	}
	inline void clear(){
		for(int idx=0; idx<sz; ++idx){
			tree[idx] = 0;
		}
	}
	T operator [] (const unsigned int idx){
		return read(idx);
	}
};

const int MxN = 100010;
vector<int> adj[MxN];
int it = 0, in[MxN], out[MxN];

void dfs(int u, int p){
	in[u] = ++it;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
	}
	out[u] = ++it;
}

inline void solution(){
	int n, q;
	cin >> n >> q;
	fenwick_tree<int> fw(2 * n);
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v); adj[v].emplace_back(u);
	}
	dfs(1, 0);
	while(q--){
		int opr, x;
		cin >> opr >> x;
		if(opr == 1){
			fw.update(in[x], 1);
			fw.update(out[x] + 1, -1);
		}
		else{
			cout << fw[in[x]] % 2 << "\n";
		}
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
//		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
