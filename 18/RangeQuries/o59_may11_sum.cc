/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sum More
 * ALGO		: 
 * DATE		: 27 Aug 2022
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
fenwick_tree<ll> fw(MxN);
vector<ll> cc;
ll k, dp[MxN], a[MxN];
int n, idx_zero, idx[MxN];

inline bool ok(ll x){
	fw.clear();
	ll cnt = 0ll;
	fw.update(idx_zero, 1ll);
	for(int i=1; i<=n; ++i){
		ll res = upper_bound;
	}
}

inline void solution(){
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		dp[i] = dp[i - 1] + a[i];
		cc.emplace_back(dp[i]);
	}

	cc.emplace_back(0ll);
	sort(cc.begin(), cc.end());
	cc.resize(uniquee(cc.begin(), cc.end()) - cc.begin());
	idx_zero = upper_bound(cc.
	for(int i=1; i<=n; ++i){

	}

	ll l = -1e18, r = 1e18;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(ok(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
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
