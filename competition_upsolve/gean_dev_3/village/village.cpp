#include "village.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

struct state_t {
  ll val;
  int idx;
  int timer;
  state_t(ll _val, int _idx, int _timer): 
    val(_val), idx(_idx), timer(_timer) {}
  bool operator < (const state_t& o) const {
    if(val != o.val) {
      return val > o.val;
    }
    if(idx != o.idx) {
      return idx > o.idx;
    }
    return timer > o.timer;
  }
};

int u[MxN], v[MxN], mem_timer[MxN];
ll w[MxN], people[MxN];
priority_queue<state_t> pq[MxN];

inline bool try_heap_push(int idx) {
  mem_timer[idx] += 1;
  ll sum_people = people[u[idx]] + people[v[idx]];
  if(sum_people >= w[idx]) {
    // did not push
    return false;
  }
  pq[u[idx]].emplace(people[u[idx]] + ((w[idx] - sum_people + 1) / 2), idx, mem_timer[idx]);
  pq[v[idx]].emplace(people[v[idx]] + ((w[idx] - sum_people + 1) / 2), idx, mem_timer[idx]);
  // pushed
  return true;
}

void init_village(int N, int M, int Q, std::vector<int> U, std::vector<int> V, std::vector<int> W) {
  for(int i=0; i<M; ++i) {
    u[i] = U[i];
    v[i] = V[i];
    w[i] = (ll) W[i];
    try_heap_push(i);
  }
}

std::vector<std::vector<int>> move_in(int K, std::vector<int> X, std::vector<int> Y) {
  vector<vector<int>> ret;
  for(int i=0; i<K; ++i) {
    vector<int> to_add;
    int adding_village = X[i];
    ll to_add_people = (ll) Y[i];
    people[adding_village] += to_add_people;
    while(!pq[adding_village].empty() && people[adding_village] >= pq[adding_village].top().val) {
      state_t cur = pq[adding_village].top();
      pq[adding_village].pop();
      if(cur.timer < mem_timer[cur.idx]) {
        continue;
      }
      if(!try_heap_push(cur.idx)) {
        to_add.push_back(cur.idx);
      }
    }
    ret.emplace_back(to_add);
  }
  return ret;
}