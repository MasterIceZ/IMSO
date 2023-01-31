/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi17_metaverse 2
 * ALGO		: 
 * DATE		: 16 Jan 2023
 * */

// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
// 
// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

const int MxN = 100010;
const int MxK = 20020;

struct segment_tree{
	int tree[MxN * 4];
	void build(int l, int r, int idx){
		memset(tree, 0x3f, sizeof tree);
//		if(l > r){
//			return ;
//		}
//		if(l == r){
//			tree[idx] = 1e9 + 100;
//			return ;
//		}
//		int mid = (l + r) >> 1;
//		build(l, mid, idx << 1);
//		build(mid + 1, r, idx << 1 | 1);
//		tree[idx] = min(tree[idx << 1], tree[idx << 1 | 1]);
	}
	void update(int l, int r, int id, int v, int idx){
		if(l > r || r < id || l > id){
			return ;
		}
		if(l == r){
			tree[idx] = min(tree[idx], v);
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, v, idx << 1);
		update(mid + 1, r, id, v, idx << 1 | 1);
		tree[idx] = min(tree[idx << 1], tree[idx << 1 | 1]);
	}
	int read(int l, int r, int wl, int wr, int idx){
		if(l > r || l > wr || r < wl){
			return 1e9 + 100;
		}
		if(wl <= l && r <= wr){
			return tree[idx];
		}
		int mid = (l + r) >> 1;
		return min(read(l, mid, wl, wr, idx << 1), read(mid + 1, r, wl, wr, idx << 1 | 1));
	}
} seg[2];

pair<int, int> in[MxK], out[MxK];
vector<int> pos_in[MxN], pos_out[MxN];
int dp[20][MxN];

inline void solution(){
	int n, m, k, p;
	cin >> n >> m >> k >> p;
	memset(dp, 0x3f, sizeof dp);
	for(int i=1; i<=k; ++i){
		cin >> in[i].first >> in[i].second >> out[i].first >> out[i].second;
		pos_in[in[i].second].emplace_back(i);
		pos_out[out[i].second].emplace_back(i);
		dp[1][i] = in[i].first + in[i].second - 2;
	}
	int answer = n + m - 2, cnt = 0;
	for(int i=2; i<=p; ++i){
		for(int j=1; j<=k; ++j){
			dp[i][j] = in[j].first + in[j].second - 2;
		}
		seg[0].build(1, n, 1);
		seg[1].build(1, n, 1);
		for(int j=1; j<=m; ++j){
			for(auto x: pos_out[j]){
				int id_x = out[x].first;
				int id_y = out[x].second;
				seg[0].update(1, n, id_x, dp[i - 1][x] - id_x - id_y, 1);
				seg[1].update(1, n, id_x, dp[i - 1][x] + id_x - id_y, 1);
			}
			for(auto x: pos_in[j]){
				int id_x = in[x].first;
				int id_y = in[x].second;
				dp[i][x] = min({dp[i][x], seg[0].read(1, n, 1, id_x, 1) + id_x + id_y, seg[1].read(1, n, id_x, n, 1) - id_x + id_y});
			}
		}
		seg[0].build(1, n, 1);
		seg[1].build(1, n, 1);
		for(int j=m; j>=1; --j){
			for(auto x: pos_out[j]){
				int id_x = out[x].first;
				int id_y = out[x].second;
				seg[0].update(1, n, id_x, dp[i - 1][x] - id_x + id_y, 1);
				seg[1].update(1, n, id_x, dp[i - 1][x] + id_x + id_y, 1);
			}
			for(auto x: pos_in[j]){
				int id_x = in[x].first;
				int id_y = in[x].second;
				dp[i][x] = min({dp[i][x], seg[0].read(1, n, 1, id_x, 1) + id_x - id_y, seg[1].read(1, n, id_x, n, 1) - id_x - id_y});
			}
		}
	}
	for(int i=1; i<=p; ++i){
		for(int j=1; j<=k; ++j){
			if(dp[i][j] + abs(n - out[j].first) + abs(m - out[j].second) < answer){
				answer = dp[i][j] + abs(n - out[j].first) + abs(m - out[j].second);
				cnt = i;
			}
		}
	}
	cout << answer << " " << cnt;
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
