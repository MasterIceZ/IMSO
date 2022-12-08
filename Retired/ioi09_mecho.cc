/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Mecho
 * ALGO		: Breadth First Search, Search by Elimination
 * DATE		: 13 Nov 2022
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

const int MxN = 880;
const int MxS = 1010;
const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

char a[MxN][MxN];
pair<int, int> expected_position, end_position;
queue<pair<int, int>> q;
int n, s, bee[MxN][MxN], dist[MxN][MxN];

inline bool inBound(int i, int j){
	if(i < 1 || j < 1 || i > n || j > n){
		return false;
	}
	return true;
}

inline bool ok(int mid){
	if(mid * s >= bee[expected_position.first][expected_position.second]){
		return false;
	}
	dbg(mid, "in");
	while(!q.empty()){
		q.pop();
	}
	memset(dist, 0, sizeof dist);
	dist[expected_position.first][expected_position.second] = s * mid;
	q.emplace(expected_position);
	while(!q.empty()){
		pair<int, int> now = q.front(); q.pop();
		if(a[now.first][now.second] == 'D'){
			return true;
		}
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(!inBound(ii, jj) || a[ii][jj] == 'T' || dist[ii][jj] || bee[ii][jj] <= (dist[ii][jj] + 1)){
				continue;
			}
			q.emplace(ii, jj);
			dist[ii][jj] = dist[now.first][now.second] + 1;
		}
	}
	return false;
}

inline void solution(){
	cin >> n >> s;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	memset(bee, -1, sizeof bee);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(a[i][j] == 'M'){
				expected_position = make_pair(i, j);
				a[i][j] = 'G';
			}
			else if(a[i][j] == 'H'){
				bee[i][j] = 0;
				q.emplace(i, j);
			}
			else if(a[i][j] == 'D'){
				end_position = make_pair(i, j);
			}
		}
	}
	while(!q.empty()){
		pair<int, int> now = q.front(); q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(!inBound(ii, jj) || a[ii][jj] != 'G' || bee[ii][jj] != -1){
				continue;
			}
			bee[ii][jj] = bee[now.first][now.second] + s;
			q.emplace(ii, jj);
		}
	}
	bee[end_position.first][end_position.second] = n * n * s;
	int l = 0, r = n * n * 2;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(ok(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << (ok(l) ? l: -1);
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
