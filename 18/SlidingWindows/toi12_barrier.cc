/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi12_barrier
 * ALGO		: Sliding Windows
 * DATE		: 15 June 2022
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

const int MxN = 6e6 + 60;
deque<pair<int, ll>> dq;
ll qs[MxN], answer;

inline void solution(){
	int n, k, cnt = 1e9 + 100;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> qs[i];
		qs[i] = qs[i - 1] + qs[i];
	}	
	dq.emplace_back(0, 0ll);
	for(int i=1; i<=n; ++i){
		while(!dq.empty() && i - dq.front().first > k){
			dq.pop_front();
		}
		while(!dq.empty() && dq.back().second >= qs[i]){
			dq.pop_back();
		}
		dq.emplace_back(i, qs[i]);
		if(qs[i] - dq.front().second > answer){
			answer = qs[i] - dq.front().second;
			cnt = 1e9 + 100;
		}
		if(qs[i] - dq.front().second == answer){
			cnt = min(cnt, i - dq.front().first);
		}
	}
	cout << answer << "\n" << (cnt >= 1e9 + 100? 0: cnt);
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
