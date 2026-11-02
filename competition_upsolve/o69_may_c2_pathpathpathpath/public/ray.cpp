#include "pathpathpathpath.h"

#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

// Query structure for Mo's Algorithm
struct Query {
  int L, R, ex, id, bi;
  bool operator<(const Query& other) const {
    if (bi != other.bi) return bi < other.bi;
    return (bi & 1) ? R > other.R : R < other.R;
  }
};

void solve(int _n, int _q, vector<int> U, vector<int> V, vector<vector<int>> A,
           vector<int> QU, vector<int> QV, vector<int>& ans_distinct,
           vector<int>& ans_mode) {
  int n = _n;
  int q = _q;

  // Shift 0-indexed input to 1-indexed
  for (auto& x : U) x++;
  for (auto& x : V) x++;
  for (auto& x : QU) x++;
  for (auto& x : QV) x++;

  // Make A 1-indexed to match tree nodes
  A.insert(A.begin(), vector<int>());

  // Build the adjacency list
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    adj[U[i]].push_back(V[i]);
    adj[V[i]].push_back(U[i]);
  }

  const int LG = 18;  // Sufficient for N up to 200,000
  vector<int> st(n + 1), en(n + 1), dep(n + 1);
  vector<int> tr(2 * n + 2);
  vector<vector<int>> par(n + 1, vector<int>(LG, 0));
  int tmr = 0;

  // DFS for Euler tour and LCA setup
  auto dfs = [&](auto& self, int u, int p) -> void {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    tr[st[u] = ++tmr] = u;
    for (int v : adj[u]) {
      if (v != p) self(self, v, u);
    }
    tr[en[u] = ++tmr] = u;
  };

  dfs(dfs, 1, 0);

  // Binary lifting table for LCA
  for (int j = 1; j < LG; j++) {
    for (int i = 0; i <= n; i++) {
      par[i][j] = par[par[i][j - 1]][j - 1];
    }
  }

  auto lca = [&](int u, int v) -> int {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = LG - 1; i >= 0; i--) {
      if (dep[u] - (1 << i) >= dep[v]) u = par[u][i];
    }
    if (u == v) return u;
    for (int i = LG - 1; i >= 0; i--) {
      if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
      }
    }
    return par[u][0];
  };

  // Mo's on Trees: Block Size Optimization
  long long S = 0;
  for (int i = 1; i <= n; i++) S += A[i].size();

  int T = 1;
  while (1LL * T * T < 2 * S) T++;

  vector<int> blk(2 * n + 2);
  int cw = 0, nb = 0;
  for (int i = 1; i <= 2 * n; i++) {
    int w = A[tr[i]].size();
    if (w > 2 * T) {
      if (cw > 0) {
        nb++;
        cw = 0;
      }
      blk[i] = nb++;
    } else if (cw > 0 && cw + w > 2 * T) {
      nb++;
      blk[i] = nb;
      cw = w;
    } else {
      blk[i] = nb;
      cw += w;
    }
  }

  // Process Queries
  vector<Query> queries(q);
  for (int i = 0; i < q; i++) {
    int u = QU[i], v = QV[i];
    int l = lca(u, v);
    if (st[u] > st[v]) swap(u, v);

    if (l == u) {
      queries[i] = {st[u], st[v], 0, i, blk[st[u]]};
    } else {
      queries[i] = {en[u], st[v], l, i, blk[en[u]]};
    }
  }

  sort(queries.begin(), queries.end());

  // Dynamically find maximum color requirement for linked-list arrays
  int max_c = 0;
  for (const auto& vec : A) {
    for (int c : vec) {
      if (c > max_c) max_c = c;
    }
  }
  int CLR_SIZE = max_c + 5;
  const int MB = 650;

  // State for Mo's Algorithm
  vector<int> vis(n + 1, 0);
  vector<int> freq(CLR_SIZE, 0);
  vector<int> prv(CLR_SIZE, 0), nxt(CLR_SIZE, 0);
  vector<int> bhd(MB + 2, 0);
  int hhd = 0;
  int distinct = 0;

  // Linked list operations to track frequency/mode
  auto ll_rm = [&](int c) {
    int f = freq[c];
    int* h = (f <= MB) ? &bhd[f] : &hhd;
    if (prv[c])
      nxt[prv[c]] = nxt[c];
    else
      *h = nxt[c];
    if (nxt[c]) prv[nxt[c]] = prv[c];
  };

  auto ll_ins = [&](int c) {
    int f = freq[c];
    int* h = (f <= MB) ? &bhd[f] : &hhd;
    nxt[c] = *h;
    prv[c] = 0;
    if (*h) prv[*h] = c;
    *h = c;
  };

  auto toggle = [&](int u) {
    vis[u] ^= 1;
    if (vis[u]) {
      for (int c : A[u]) {
        if (freq[c] > 0) ll_rm(c);
        if (freq[c]++ == 0) ++distinct;
        ll_ins(c);
      }
    } else {
      for (int c : A[u]) {
        ll_rm(c);
        if (--freq[c] == 0) --distinct;
        if (freq[c] > 0) ll_ins(c);
      }
    }
  };

  auto get_mode_internal = [&]() -> int {
    int best = 0, bf = 0;
    for (int c = hhd; c; c = nxt[c]) {
      if (freq[c] > bf) {
        bf = freq[c];
        best = c;
      }
    }
    for (int f = MB; f > bf; f--) {
      if (bhd[f]) return bhd[f];
    }
    return best;
  };

  // Output assignments
  ans_distinct.assign(q, 0);
  ans_mode.assign(q, 0);

  // Expand/Shrink windows
  int cL = 1, cR = 0;
  for (const auto& Q : queries) {
    while (cL > Q.L) toggle(tr[--cL]);
    while (cR < Q.R) toggle(tr[++cR]);
    while (cL < Q.L) toggle(tr[cL++]);
    while (cR > Q.R) toggle(tr[cR--]);

    if (Q.ex) {
      toggle(Q.ex);
      ans_distinct[Q.id] = distinct;
      ans_mode[Q.id] = get_mode_internal();
      toggle(Q.ex);  // Toggle back
    } else {
      ans_distinct[Q.id] = distinct;
      ans_mode[Q.id] = get_mode_internal();
    }
  }
}