/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Romance of Three Kingdoms
 * ALGO		: 
 * DATE		: 1 Oct 2022
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

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

const int MxN = 55;
char a[MxN][MxN];
int comp[MxN][MxN], n, m, dist[MxN][MxN], min_dist[5];
queue<pair<int, int>> q;

inline void fill_comp(int sti, int stj, int c){
	q.emplace(sti, stj);
	comp[sti][stj] = c;
	while(!q.empty()){
		pair<int, int> now = q.front(); q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m || comp[ii][jj] || a[ii][jj] != 'X'){
				continue;
			}
			comp[ii][jj] = c;
			q.emplace(ii, jj);
		}	
	}
}

inline void fill_all(int sti, int stj){
	memset(dist, -1, sizeof dist);
	memset(min_dist, 0x3f, sizeof dist);
	dist[sti][stj] = 0;
	q.emplace(sti, stj);
	while(!q.empty()){
		pair<int, int> now = q.front(); q.pop();
		if(comp[now.first][now.second]){
			min_dist[comp[now.first][now.second]] = min(min_dist[comp[now.first][now.second]], dist[now.first][now.second]);
		}
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m || dist[ii][jj] != -1){
				continue;
			}
			dist[ii][jj] = dist[now.first][now.second] + 1;
			q.emplace(ii, jj);
		}
	}
}

inline void solution(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	int it = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == 'X' && !comp[i][j]){
				fill_comp(i, j, ++it);
			}
		}
	}
	int answer = 1e9 + 100;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			fill_all(i, j);
			answer = min(answer, min_dist[1] + min_dist[2] + min_dist[3]);
		}
	}
	cout << 
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
