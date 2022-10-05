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

const int MxN = 1010;
char a[MxN][MxN];
int n, m;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

// const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// stack memory -> ~ (n x m) -> (30 x 30)
void dfs(int i, int j){
	for(int k=0; k<4; ++k){
		int ii = i + di[k];
		int jj = j + dj[k];
		if(ii < 1 || jj < 1 || ii > n || jj > m){
			continue;
		}	
		if(a[ii][jj] == '*'){
			continue;
		}
		a[ii][jj] = '*';
		dfs(ii, jj);
	}
}

queue<pair<int, int>> q;
// (n x m) -> (1000 x 1000)
void bfs(int i, int j){
	a[i][j] = '*';
	q.emplace(i, j);
	while(!q.empty()){
		pair<int, int> now = q.front(); q.pop();
		for(int k=0; k<4; ++k){
			int ii = now.first + di[k];
			int jj = now.second	+ dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}	
			if(a[ii][jj] == '*'){
				continue;
			}
			a[ii][jj] = '*';
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
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == '*'){
				continue;
			}		
			a[i][j] = '*';
			dfs(i, j);
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
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
