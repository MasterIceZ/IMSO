/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

struct state_t {
	int i, j, last, w;
	bool operator < (const state_t& o) const {
		return w > o.w;
	}
	state_t(int _i, int _j, int _last, int _w):
		i(_i), j(_j), last(_last), w(_w) {}
};

const int di[] = {0, -1, 1}, dj[] = {1, 0, 0};
priority_queue<state_t> pq;

inline void solution(){
	int n, m, s;
	cin >> n >> m >> s;
	vector<vector<char>> a(n + 1, vector<char> (m + 1));
	vector<vector<vector<int>>> dist(3, vector<vector<int>> (n + 1, vector<int> (m + 1, 1e9 + 100)));
	for(int i=1; i<=n; ++i) {
		string _;
		cin >> _;
		for(int j=1; j<=m; ++j) {
			a[i][j] = _[j - 1];
		}
	}
	pq.emplace(s, 1, 0, 0);
	dist[0][s][1] = 0;
	while(!pq.empty()) {
		state_t now = pq.top(); pq.pop();
		if(now.j == m) {
			cout << now.w;
			return ;
		}
		for(int k=0; k<3; ++k) {
			int ii = di[k] + now.i, jj = dj[k] + now.j;
			if(ii < 1 || jj < 1 || ii > n || jj > m) {
				continue;
			}
			if(a[ii][jj] == '#') {
				continue;
			}
			int nxt = now.w + (now.last != k);
			if(dist[now.last][ii][jj] > nxt) {
				pq.emplace(ii, jj, k, dist[now.last][ii][jj] = nxt);
			}
		}
	}
	cout << -1;
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
