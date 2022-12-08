/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: migration
 * ALGO		: Dijkstra
 * DATE		: 12 Nov 2022
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

const int MxN = 33;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

struct Node{
	int i, j, w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int _i, int _j, int _w):
		i(_i), j(_j), w(_w) {}
};

int d[MxN][MxN][MxN][MxN], n, m;
char a[MxN][MxN];
priority_queue<Node> pq;

inline void solution(){
	int q;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	memset(d, 0x3f, sizeof d);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == '#'){
				continue;
			}
			pq.emplace(i, j, d[i][j][i][j] = 0);
			while(!pq.empty()){
				Node now = pq.top(); pq.pop();
				for(int k=0; k<4; ++k){
					int ii = di[k] + now.i;
					int jj = dj[k] + now.j;
					if(ii < 1 || jj < 1 || ii > n || jj > m){
						continue;
					}
					if(a[ii][jj] == '#'){
						continue;
					}
					int nxt = max(now.w, abs(i - ii));
					if(d[i][j][ii][jj] > nxt){
						pq.emplace(ii, jj, d[i][j][ii][jj] = nxt);
					}
				}
			}
		}
	}
//	for(int i=1; i<=n; ++i){
//		for(int j=1; j<=m; ++j){
//			cout << d[2][1][i][j] << " ";
//		}
//		cout << "\n";
//	}
	while(q--){
		int a, b, x, y, l;
		cin >> a >> b >> x >> y >> l;
		dbg(a, b, x, y, l);
		cout << (d[a][b][x][y] <= l) << "\n";
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
