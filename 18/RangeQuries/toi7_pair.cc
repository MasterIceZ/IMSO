/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi7_pair
 * ALGO		: Fenwick Tree, Inversion Count
 * DATE		: 4 Sep 2022
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

template <typename T> 
class fenwick_tree{
protected:
	unsigned int offset = 1024;
private:
	unsigned int sz;
	T *tree;
public:
	fenwick_tree(const unsigned int _sz){
		sz = _sz + offset;
		tree = (T*) calloc(sz, sizeof(T));
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
	T operator [] (const unsigned int idx){
		return reada(idx);
	}
};

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i] >> b[i];
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
