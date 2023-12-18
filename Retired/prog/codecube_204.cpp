/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Lazanta
 * ALGO		: Dijkstra
 * DATE		: 13 Dec 2023
 * */

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //
#define _DEBUG
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

const int MxN = 50050;

struct state_t {
  int v, w, mask;
  bool operator < (const state_t &o) const {
    return w > o.w;
  }
  state_t(int _v, int _w, int _mask):
    v(_v), w(_w), mask(_mask) {}
};

vector<pair<int, int>> adj[MxN];
priority_queue<state_t> pq;
int dist[1 << 4][MxN], add_state[300];

inline void solution(){
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  t = "$" + t;
  int init_state = 0;
  for(int i=0; i<4; ++i) {
    if(s[i] == '_') {
      continue;
    }
    init_state |= (1 << i);
  }
  for(int i=1, u, v, w; i<=m; ++i) {
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  memset(dist, 0x3f, sizeof dist);
  pq.emplace(1, dist[init_state | add_state[t[1]]][1] = 0, init_state | add_state[t[1]]);
  while(!pq.empty()) {
    state_t now = pq.top(); pq.pop();
    dbg(now.v, now.w, now.mask);
    for(auto x: adj[now.v]) {
      int nxt = now.w + x.second;
      int nxt_mask = (now.mask | add_state[t[x.first]]);
      if(dist[nxt_mask][x.first] > nxt) {
        pq.emplace(x.first, dist[nxt_mask][x.first] = nxt, nxt_mask);
      }
    }
  }
  cout << dist[15][n];
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
  add_state['X'] = 1;
  add_state['M'] = 2;
  add_state['A'] = 4;
  add_state['S'] = 8;
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
