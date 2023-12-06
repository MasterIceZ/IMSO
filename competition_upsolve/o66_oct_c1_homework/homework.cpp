#include <bits/stdc++.h>
#include "homework.h"

using namespace std;

struct state_t {
  int v;
  long long prio;
  bool operator < (const state_t& o) const {
    if(prio != o.prio) {
      return prio > o.prio;
    }
    return v > o.v;
  }
  state_t(int _v, long long _prio):
    v(_v), prio(_prio) {}
};

vector<vector<int>> adj;
priority_queue<state_t> pq;
vector<int> require, cnt_require;
vector<long long> start_time, finish_time, divisor;
vector<bool> done;

inline long long getNextTime(long long minimum_time, long long div) {
  if(minimum_time % div == 0ll) {
    return minimum_time;
  }
  return div * (minimum_time / div + 1ll);
}

int homework(int N, std::vector<std::vector<int>> HW, std::vector<std::vector<int>> B) {
  adj.resize(N);
  start_time.resize(N);
  finish_time.resize(N);
  divisor.resize(N);
  require.resize(N);
  cnt_require.resize(N);
  done.resize(N); 
  for (int i = 0; i < N; ++i) {
    for(auto x: B[i]) {
      adj[x].emplace_back(i);
    }
  }
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    start_time[i] = (long long) HW[i][0];
    finish_time[i] = (long long) HW[i][1];
    divisor[i] = (long long) HW[i][2];
    require[i] = HW[i][3];

    long long next_time = getNextTime(start_time[i], divisor[i]);
    if(require[i] == 0 && next_time <= finish_time[i]) {
      done[i] = true;
      pq.emplace(i, next_time + 1ll);
      cnt++;
    }
  }
  while (!pq.empty()) {
    state_t now = pq.top();
    pq.pop();
    for (auto x: adj[now.v]) {
      if(done[x]) {
        continue;
      }
      cnt_require[x]++;
      int next_time = getNextTime(max(start_time[x], now.prio), divisor[x]);
      if(cnt_require[x] >= require[x] && next_time <= finish_time[x]) {
        done[x] = true;
        cnt++;
        pq.emplace(x, next_time + 1ll);
      }
    }
  }
  return cnt;
}