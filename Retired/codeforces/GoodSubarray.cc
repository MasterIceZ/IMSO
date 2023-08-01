/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

const int MxN = 200020;

ll a[MxN];
deque<ll> dq;

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	while(!dq.empty()) {
		dq.pop_front();
	}
	ll answer = 0ll;
	for(int i=1; i<=n; ++i) {
		dq.emplace_back(a[i]);
		while(!dq.empty() && a[i] < dq.size()) {
			dq.pop_front();
		}
		ll cur_size = (ll) dq.size();
		answer += (cur_size + 1ll) * cur_size / 2ll;
		answer -= (cur_size - 1ll) * cur_size / 2ll;
	}
	cout << answer;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
