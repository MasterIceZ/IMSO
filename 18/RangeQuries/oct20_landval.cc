/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

const int MxN = 200020;

template<typename T>
class fenwick_tree{
private:
	T* tree;
	unsigned int sz;
public:
	fenwick_tree(unsigned int _sz){
		sz = _sz + 16;
		tree = (T *) calloc(sz, sizeof (T));
	}
	void update(unsigned int idx, T v){
		for(; idx<=sz; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	T read(unsigned int idx){
		T res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
	T operator [] (const unsigned int idx){
		return read(idx) - read(idx - 1);
	}
};

inline void solution(){
	int n, q, a, b, c, d, x;
	cin >> n >> q;
	fenwick_tree<int> fw(n);
	while(q--){
		cin >> a;
		if(a == 1){
			cin >> b >> c >> d;
			fw.update(b, d);
			fw.update(c + 1, -d);
		}
		else{
			cin >> x;
			cout << fw[x] << "\n";
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
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
