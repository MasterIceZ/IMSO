/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Hot
 * ALGO		: Dijkstra
 * DATE		: 20 Mar 2023
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

struct State{
	int i, j, w;
	bool operator < (const State& o) const {
		return w > o.w;
	}
	State(int _i, int _j, int _w):
		i(_i), j(_j), w(_w) {}
};

const int MxN = 1010;
int a[MxN][MxN], dist[MxN][MxN];
priority_queue<State> pq;
pair<int, int> edp;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
			dist[i][j] = 1e9 + 100;
			if(a[i][j] == 0 && pq.empty()){
				pq.emplace(i, j, 0);
				dist[i][j] = 0;
			}
			else if(a[i][j] == 0){
				edp = make_pair(i, j);
			}
		}
	}
	while(!pq.empty()){
		State now = pq.top(); pq.pop();
		for(int k=0; k<4; ++k){
			int ii = now.i + di[k];
			int jj = now.j + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > n){
				continue;
			}
			if(dist[ii][jj] > max(a[ii][jj], now.w)){
				pq.emplace(ii, jj, dist[ii][jj] = max(a[ii][jj], now.w));
			}
		}
	}
	cout << dist[edp.first][edp.second];
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
