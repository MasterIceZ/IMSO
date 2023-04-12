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

const int MxN = 100010;

int a[MxN];

struct fenwick_tree{
	ll t[MxN];
	void update(int idx, ll v){
		for(; idx<MxN; idx+=idx&-idx){
			t[idx] += v;
		}
	}
	ll query(int idx){
		ll res = 0;
		for(; idx>0; idx-=idx&-idx){
			res += t[idx];
		}
		return res;
	}
	void build(int n){
		for(int i=1; i<=n; ++i){
			int nxt = i + (i & -i);
			t[i] += a[i];
			if(nxt < MxN){
				t[nxt] += t[i];
			}
		}
	}
} fw;

inline void solution(){
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	fw.build(n);
	while(q--){
		int opr, x, y;
		cin >> opr >> x >> y;
		if(opr == 1){
			fw.update(x, y);
		}
		else{
			cout << fw.query(y) - fw.query(x - 1) << "\n";
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
		//cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
