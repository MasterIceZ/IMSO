/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Flash GCD
 * ALGO		:
 * DATE		: 11 Mar 2023
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
const int MxA = 1000010;
const int MxK = 22;
const ll MOD = 1e9 + 7;

int n, a[MxN];
ll answer = 0ll;

struct segment_tree{
	int tree[MxN << 2];
	void build(int l, int r, int idx){
		if(l > r){
			return ;
		}
		if(l == r){
			tree[idx] = a[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1); build(mid + 1, r, idx << 1 | 1);
		tree[idx] = __gcd(tree[idx << 1], tree[idx << 1 | 1]);
	}
	int query(int l, int r, int wl, int wr, int idx){
		if(l > r || l > wr || r < wl){
			return 0;
		}
		if(wl <= l && r <= wr){
			return tree[idx];
		}
		int mid = (l + r) >> 1;
		return __gcd(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
	}
} seg;

bool ok(int l, int mid){
	int gcd = seg.query(1, n, l, mid, 1);
	return gcd == 1;
}

inline void solution(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	seg.build(1, n, 1);
	for(int i=1; i<=n; ++i){
		if(a[i] == 1){
			dbg(i, i, to_string(a, i, i));
			dbg(n - i + 1);
			answer = (answer + (n - i + 1)) % MOD;
			continue;
		}
		int l = i, r = n;
		while(l < r){
			int mid = (l + r) >> 1;
			bool _ok = ok(l, mid);
			dbg(l, mid, r, _ok);
			if(!_ok){
				l = mid + 1;
			}
			else{
				r = mid;
			}
		}
		dbg(l);
		if(ok(i, l)){
			dbg(i, l, to_string(a, i, l));
			dbg(n - l + 1);
			answer = (answer + (n - l + 1)) % MOD;
		}
	}
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
