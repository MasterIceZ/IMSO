/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Random Update Query
 * ALGO		: Segment Tree, Lazy Propagation
 * DATE		: 11 Dec 2023
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

const ll MOD = 998244353ll;
const int MxN = 200020;

ll a[MxN];

struct node_t {
  ll v;
  node_t operator + (const node_t &o) const {

  }
  node_t(ll _v): 
    v(_v) {}
};

struct segment_tree {
  node_t t[MxN << 2];
  void build(int l, int r, int idx) {
    if(l > r) {
      return ;
    }
    if(l == r) {
      t[idx] = node_t(a[l]);
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx << 1);
    build(mid + 1, r, idx << 1 | 1);
    t[idx] = t[idx << 1] + t[idx << 1 | 1];
  }
} seg;

inline void solution(){
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  seg.build(1, n, 1);
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
