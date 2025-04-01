#include "antenna.h"

#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;
const int MxA = 1000010;

// A[i] <= 10^6

int n, a[MxN], l[MxN], r[MxN], root, c[MxN], sz[MxN], heavy[MxN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> queries[MxN];
vector<long long> answer;

struct SegmentTree {
  long long sum[MxA << 2];
  int cnt[MxA << 2];
  void update(int l, int r, int id, long long s, int c, int idx) {
    if(l > r || l > id || r < id) {
      return ;
    }
    sum[idx] += s;
    cnt[idx] += c;
    if(l == r) {
      return ;
    }
    int mid = (l + r) >> 1;
    update(l, mid, id, s, c, idx << 1);
    update(mid + 1, r, id, s, c, idx << 1 | 1);
  }
  void update(int v, int c) {
    update(1, MxA, v, 1ll * v * c, c, 1);
  }
  long long query(int l, int r, int k, int idx) {
    if(cnt[idx] < k) {
      return -1ll;
    }
    if(l == r) {
      return 1ll * k * l;
    }
    int mid = (l + r) >> 1;
    if(cnt[idx << 1] >= k) {
      return query(l, mid, k, idx << 1);
    }
    else {
      return query(mid + 1, r, k - cnt[idx << 1], idx << 1 | 1) + sum[idx << 1];
    }
  }
} seg;

inline void build_cartesian_tree() {
  stack<int> st;
  for (int i=1; i<=n; ++i) {
    while (!st.empty() && a[st.top()] < a[i]) {
      l[i] = st.top();
      st.pop();
    }
    if (st.empty()) {
      root = i;
    } else {
      r[st.top()] = i;
    }
    st.emplace(i);
  }
}

void dfs(int u) {
  if(u == 0) {
    return ;
  }
  dfs(l[u]);
  dfs(r[u]);
  sz[u] = sz[l[u]] + sz[r[u]] + 1;
  heavy[u] = sz[l[u]] > sz[r[u]] ? l[u]: r[u];
}

void insert(int val, int cnt) {
  pq.emplace(val, cnt);
  seg.update(val, cnt);
}

void dfs_fill(int u, int w) {
  if(u == 0) {
    return ;
  }
  insert(w, 1);
  dfs_fill(l[u], max(w, a[u] - a[l[u]]));
  dfs_fill(r[u], max(w, a[u] - a[r[u]]));
}

void sack(int u, bool del) {
  if(u == 0 || heavy[u] == 0) {
    return ;
  }
  int light = l[u] ^ r[u] ^ heavy[u];
  sack(light, true);
  sack(heavy[u], false);
  int cnt = 1, w = a[u] - a[heavy[u]];
  while(!pq.empty() && pq.top().first < w) {
    auto [v, c] = pq.top();
    pq.pop();
    cnt += c;
    seg.update(v, -c);
  }
  insert(w, cnt);
  dfs_fill(light, a[u] - a[light]);

  for(auto [i, k]: queries[u]) {
    answer[i] = seg.query(1, MxA, k, 1);
  }

  if(del) {
    while (!pq.empty()) {
      auto [v, c] = pq.top();
      pq.pop();
      seg.update(v, -c);
    }
  }
}

vector<long long> transfer_problem(int N, int Q, vector<int> A, vector<int> S, vector<int> K) {
  n = N;
  answer.assign(Q, -1ll);
  for(int i=1; i<=n; ++i) {
    a[i] = A[i - 1];
  }
  for(int i=0; i<Q; ++i) {
    queries[S[i] + 1].emplace_back(i, K[i]);
  }
  build_cartesian_tree();
  dfs(root);
  sack(root, false);
  return answer;
}
