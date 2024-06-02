#include <bits/stdc++.h>
#include "security.h"

using namespace std;
using ll = long long;

const int MxN = 800080;

struct state_t {
  int v;
  ll w;
  bool operator < (const state_t &o) const {
    return w > o.w;
  }
  state_t(int _v, ll _w):
    v(_v), w(_w) {}
};

struct convex_hull_trick {
  struct line_t {
    ll m, c;
    inline ll query(ll x) {
      return m * x + c;
    }
    line_t(ll _m, ll _c):
      m(_m), c(_c) {}
  };
  deque<line_t> dq;
  inline bool is_bad(line_t l1, line_t l2, line_t l3) {
    return (1.l *(l2.c - l1.c) * (l1.m - l3.m)) >= 1.l * (l3.c - l1.c) * (l1.m - l2.m);
  }
  inline void add_line(ll m, ll c) {
    line_t new_line(m, c);
    while((int) dq.size() > 1 && is_bad(dq[(int) dq.size() - 2], dq[(int) dq.size() - 1], new_line)) {
      dq.pop_back();
    }
    dq.emplace_back(new_line);
  }
  inline ll query(ll x) {
    int l = 0, r = dq.size() - 1;
    while(l < r) {
      int mid = (l + r) / 2;
      if(dq[mid].query(x) <= dq[mid + 1].query(x)) {
        r = mid;
      }
      else {
        l = mid + 1;
      }
    }
    return dq[l].query(x);
  }
};

convex_hull_trick cht;
priority_queue<state_t> pq;
int deg[MxN];
vector<ll> order_val;
vector<int> adj[MxN];
bitset<MxN> visited;
bool can;

void kingdom(int N, int M, int Q, vector<int> u, vector<int> v, vector<int> s) {
  for(int i=0; i<M; ++i) {
    adj[u[i]].emplace_back(v[i]);
    adj[v[i]].emplace_back(u[i]);

    deg[u[i]]++;
    deg[v[i]]++;
  }
  for(int i=0; i<N; ++i) {
    if(deg[i] > 1) {
      continue;
    }
    visited[i] = true;
    pq.emplace(i, (ll) s[i]);
  }
  while(!pq.empty()) {
    state_t now = pq.top();
    pq.pop();
    order_val.emplace_back((ll) now.w);
    for(auto x: adj[now.v]) {
      if(!visited[x] && --deg[x] == 1) {
        visited[x] = true;
        pq.emplace(x, s[x]);
      }
    }
  }
  can = ((int) order_val.size() == N);
  for(int i=0; i<(int) order_val.size(); ++i) {
    cht.add_line(i + 1, -order_val[i]);
  }
}

long long answer_query(int a) {
    if(!can) {
      return -1ll;
    }
    return max(0ll, -cht.query(a));
}
