/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Muscle Man
 * ALGO		: Fenwick Tree
 * DATE		: 10 Nov 2022
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
int fenwick[MxN], a[MxN];

inline void update(int idx, int v){
	for(; idx<MxN; idx+=idx&-idx){
		fenwick[idx] = fenwick[idx] + v;
	}
}

inline int query(int idx){
	int res = 0;
	for(; idx>0; idx-=idx&-idx){
		res = res + fenwick[idx];
	}
	return res;
}

inline bool ok(int i, int mid){
	return query(mid) >= a[i];
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		fenwick[i] = i & -i;
	}
	update(1, -1);
	stack<int> answer;
	for(int i=n; i>=1; --i){
		int l = 1, r = n;
		while(l < r){
			int mid = (l + r) >> 1;
			if(ok(i, mid)){
				r = mid;
			}
			else{
				l = mid + 1;
			}
		}
		update(r, -1);
		answer.emplace(n - r + 1);
	}
	while(answer.size()){
		cout << answer.top() << " ";
		answer.pop();
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
