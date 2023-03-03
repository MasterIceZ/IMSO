/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Chan Party
 * ALGO		: Dijkstra
 * DATE		: 25 Jan 2023
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
	int i, j;
	ll w;
	bool operator < (const State &o) const {
		return w > o.w;
	}
	State(int _i, int _j, ll _w):
		i(_i), j(_j), w(_w) {}
};

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

const int MxN = 1010;
ll w[MxN][MxN], m, sum, maxx;
priority_queue<State> pq;
bitset<MxN> visited[MxN];

inline void solution(){
	int n, x, y;
	cin >> n >> m >> x >> y;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> w[i][j];
		}
	}
	memset(visited, false, sizeof visited);
	pq.emplace(x, y, w[x][y]);
	sum = maxx = 0ll;
	while(!pq.empty()){
		State now = pq.top(); pq.pop();
		if(visited[now.i][now.j]){
			continue;
		}
		sum += now.w;
		maxx = max(maxx, now.w);
		visited[now.i][now.j] = true;
		if(sum >= m){
			break;
		}
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.i;
			int jj = dj[k] + now.j;
			if(ii < 1 || jj < 1 || ii > n || jj > n || visited[ii][jj]){
				continue;
			}
			pq.emplace(ii, jj, w[ii][jj]);
		}
	}
	cout << maxx;
	while(!pq.empty()){
		pq.pop();
	}
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
