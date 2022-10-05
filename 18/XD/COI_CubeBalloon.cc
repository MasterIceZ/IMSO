/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: COI_Cube Balloon
 * ALGO		: 
 * DATE		: 25 Sep 2022
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

struct Query{
	int idx, value, timer;
	bool operator < (const Query& o) const {
		return timer > o.timer;
	}
	Query(int _idx, int _value, int _timer):
		idx(_idx), value(_value), timer(_timer) {}
};

const int MxN = 100010;
int a[MxN], parent[MxN];
priority_queue<Query> pq;

inline int find_root(int idx){
	while(parent[idx] != idx){
		idx = parent[idx];
	}
	return idx;
}

inline void cut(int idx){
	int idx_value = a[idx];
	while(parent[idx] != idx){
		a[idx] -= idx_value;
		idx = parent[idx];
	}
	parent[idx] = idx;
	return ;
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		parent[i] = i;
	}
	for(int opr, i=1; i<=m; ++i){
	
		while(!pq.empty() && pq.top().timer == i){
			Query now = pq.top(); pq.pop();
			int ridx = find_root(now.idx);
			a[ridx] += now.value;
		}

		cin >> opr;
		if(opr == 1){
			int x;
			cin >> x;
			cut(x);
		}
		else if(opr == 2){
			int a, b, t, v;
			cin >> a >> b >> t >> v;
			int ra = find_root(a), rb = find_root(b);
			if(ra == rb && parent[a] == a){
				continue;
			}
			cut(a);
			parent[a] = rb;
			::a[rb] += ::a[a];
			pq.emplace(a, v, t);
		}
		else{
			int x;
			cin >> x;
			cout << a[find_root(x)] << "\n";
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
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
