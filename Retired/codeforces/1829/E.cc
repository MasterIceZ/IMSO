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

inline void solution(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int> (m + 1));
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	queue<pair<int, int>> q;
	vector<int> di = {-1, 0, 0, 1}, dj = {0, -1, 1, 0};
	int answer = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == 0){
				continue;
			}
			q.emplace(i, j);
			int sum = 0;
			sum += a[i][j];
			a[i][j] = 0;
			while(!q.empty()){
				pair<int, int> now = q.front(); q.pop();
				for(int k=0; k<4; ++k){
					int ii = di[k] + now.first;
					int jj = dj[k] + now.second;
					if(ii < 1 || jj < 1 || ii > n || jj > m){
						continue;
					}
					if(a[ii][jj] == 0){
						continue;
					}
					q.emplace(ii, jj);
					sum += a[ii][jj];
					a[ii][jj] = 0;
				}
			}
			answer = max(answer, sum);
		}
	}
	cout << answer;
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
