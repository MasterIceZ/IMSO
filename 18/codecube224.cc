/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Lion Army
 * ALGO		: Disjoint Set Union
 * DATE		: 14 Oct 2022
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

const int MxN = 300030;
const ll MOD = 1e9 + 7;
int parent[MxN << 1];

int find_root(int u){
	dbg(u, parent[u]);
	return u == parent[u] ? u: parent[u] = find_root(parent[u]);
}

ll mod_of_power(ll a, ll b){
	if(b == 0ll){
		return 1ll;
	}
	ll t = mod_of_power(a, b >> 1ll);
	t = (t * t) % MOD;
	if(b & 1ll){
		t = (t * a) % MOD;
	}
	dbg("power", t);
	return t;
}

inline void solution(){
	int n, q, t, a, b;
	cin >> n >> q;
	ll state = n;
	for(int i=1; i<=600010; ++i){
		parent[i] = i;
	}
	bool not_ok = false;
	while(q--){
		cin >> t >> a >> b;
		int like_a = a;
		int like_b = b;
		int hate_a = n + a;
		int hate_b = n + b;
		if(!t){
			swap(like_b, hate_b);
		}
		int rla = find_root(like_a);
		int rlb = find_root(like_b);
		int rha = find_root(hate_a);
		int rhb = find_root(hate_b);
		dbg(rla, rlb, rha, rhb);
		if(rla == rlb){
			dbg("1", state);
			cout << (not_ok? 0: mod_of_power(2ll, state)) << "\n";
			continue;
		}
		parent[find_root(like_a)] = find_root(like_b);
		parent[find_root(hate_a)] = find_root(hate_b);
		state = state - 1ll;
		dbg(find_root(like_a), find_root(hate_a));
		if(not_ok || find_root(like_a) == find_root(hate_a)){
			not_ok = true;
			dbg("0");
			cout << "0\n";
		}
		else{
			dbg("2", state);
			cout << mod_of_power(2ll, state) << "\n";
			dbg("2", "ENDED");
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
