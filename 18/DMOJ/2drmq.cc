/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 2-Dimensional Range Minimum Query
 * ALGO		: 2D Sparse Table
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

const int MxN = 1010;
const int LG = 16;
int sparse_table[LG][LG][MxN][MxN];
int lg[MxN];

void init(std::vector<std::vector<int>> arr){
	int n = arr.size();
	for(int state=2; state<MxN; ++state){
		lg[state] = lg[state >> 1] + 1;
	}
	memset(sparse_table, 0x3f, sizeof sparse_table);
	// base case
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			sparse_table[0][0][i][j] = arr[i][j];
		}
	}
	// precompute
	for(int state_i=0; state_i<LG; ++state_i){
		for(int state_j=0; state_j<LG; ++state_j){
			if(state_i + state_j == 0){
				continue;
			}
			for(int i=0; i+(1 << state_i)<=n; ++i){
				for(int j=0; j+(1 << state_j)<=n; ++j){
					if(state_i == 0){
						sparse_table[state_i][state_j][i][j] = min(sparse_table[state_i][state_j - 1][i][j], sparse_table[state_i][state_j - 1][i][j + (1 << (state_j - 1))]);
					}
					else{
						sparse_table[state_i][state_j][i][j] = min(sparse_table[state_i - 1][state_j][i][j], sparse_table[state_i - 1][state_j][i + (1 << (state_i - 1))][j]);
					}
				}
			}
		}
	}
}

int query(int a, int b, int c, int d){
	swap(c, b);
	c++, d++;
	int state_i = lg[c - a], state_j = lg[d - b];
	int A = sparse_table[state_i][state_j][a][b];
	int B = sparse_table[state_i][state_j][c - (1 << state_i)][b];
	int C = sparse_table[state_i][state_j][a][d - (1 << state_j)];
	int D = sparse_table[state_i][state_j][c - (1 << state_i)][d - (1 << state_j)];
	return min({A, B, C, D});
}

#ifdef _DEBUG

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	vector<vector<int>> arr(n, vector<int> (n, 0));
	for(auto &v: arr){
		for(auto &x: v){
			cin >> x;
		}
	}
	dbg(arr);
	init(arr);
	int a, b, c, d;
	while(q--){
		cin >> a >> b >> c >> d;
		cout << query(a, b, c, d) << "\n";
	}
}

#endif
