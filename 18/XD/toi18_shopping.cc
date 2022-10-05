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

const int MxN = 500050;
ll a[MxN], cost[MxN], score[MxN];
// score[i] -> คะแนนที่ได้รับเมื่อเดินจาก 1 -> i
// cost[i] -> ราคาที่ต้องจ่ายเมื่อเดินจาก 1 -> i

inline void solution(){
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		if(a[i] >= 0){
			score[i] += a[i];
		}
		else{
			cost[i] -= a[i];
		}
		score[i] = score[i - 1] + score[i];
		cost[i] = cost[i - 1] + cost[i];
	}
	while(q--){
		int start_point, money;
		cin >> start_point >> money;
		int most_right = lower_bound(cost + 1, cost + n + 1, money + cost[start_point]) - (cost + 1);
		cout << score[most_right] - score[start_point] << "\n";
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
