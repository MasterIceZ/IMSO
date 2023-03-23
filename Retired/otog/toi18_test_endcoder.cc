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
int n, m, c[MxN][MxN][2];
char a[MxN][MxN];

char divide(int x_1, int y_1, int x_2, int y_2){
	int cnt_x = (x_2 - x_1 + 1), cnt_y = (y_2 - y_1 + 1);
	if(cnt_x * cnt_y == c[x_2][y_2][0] - c[x_1 - 1][y_2][0] - c[x_2][y_1 - 1][0] + c[x_1 - 1][y_1 - 1][0]){
		cout << "0";
		return '0';
	}
	if(cnt_x * cnt_y == c[x_2][y_2][1] - c[x_1 - 1][y_2][1] - c[x_2][y_1 - 1][1] + c[x_1 - 1][y_1 - 1][1]){
		cout << "1";
		return '1';
	}
	int mid_x = (x_1 + x_2) >> 1;
	int mid_y = (y_1 + y_2) >> 1;
	cout << "D";
	divide(x_1, y_1, mid_x, mid_y);
	divide(x_1, mid_y + 1, x_2, mid_y);
}

inline void solution(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		string s;
		cin >> s;
		for(int j=1; j<=m; ++j){
			a[i][j] = s[j - 1];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			c[i][j][a[i][j] - '0']++;
			c[i][j][0] = c[i][j][0] + c[i][j - 1][0] + c[i - 1][j][0] - c[i - 1][j - 1][0];
			c[i][j][1] = c[i][j][1] + c[i][j - 1][1] + c[i - 1][j][1] - c[i - 1][j - 1][1];
		}
	}
	divide(1, 1, n, m);
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
