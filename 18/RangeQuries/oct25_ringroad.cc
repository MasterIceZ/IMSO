/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct25_ringroad
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

const int MxN = 200020;
int ring[MxN], parent[MxN], circle, dist[MxN];

struct fenwick_tree{
	int tree[MxN];
	void update(int idx, int v){
		for(; idx<=200000; idx+=idx&-idx){
			tree[idx] = tree[idx] + v;
		}
	}
	int read(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res = res + tree[idx];
		}
		return res;
	}
} fw;

inline int get_dist(int a, int b){
	return abs(dist[a] - dist[b]);
}

inline int get_circle(int a, int b){
	if(a > b){
		swap(a, b);
	}
	int a_to_b = fw.read(b - 1) - fw.read(a - 1);
	return min(a_to_b, circle - a_to_b);
}

inline void solution(){
	int n, k, q;
	cin >> n >> k >> q;
	for(int i=1; i<=k; ++i){
		cin >> ring[i];
		circle = circle + ring[i];
		parent[i] = i;
		if(i < k){
			fw.update(i, ring[i]);
		}
	}
	for(int i=k+1, a, b; i<=n; ++i){
		cin >> a >> b;
		parent[i] = parent[a];
		dist[i] = dist[a] + b;
	}
	while(q--){
		int opr;
		cin >> opr;
		if(opr == 1){
			int a, b;
			cin >> a >> b;
			if(parent[a] == parent[b]){
				cout << get_dist(a, b);
			}
			else{
				cout << get_dist(a, parent[a]) + get_dist(parent[b], b) + get_circle(parent[a], parent[b]);
			}
			cout << "\n";
		}
		else{
			int a, b;
			cin >> a >> b;
			if(a == k){
				int last = circle - fw.read(k);
				circle = circle - last + b;
			}
			else{
				int last = fw.read(a) - fw.read(a - 1);
				circle = circle - last + b;
				fw.update(a, b - last);
			}
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
