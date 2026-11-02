#include "pathpathpathpath.h"

#include <algorithm>
#include <vector>

const int MxN = 100010;
const int BLK = 666;
const int LG = 22;
const int MxC = 200020;
const int MxG = 400040;

int blk[2 * MxN];

struct query_t {
  int l, r, lca, idx, u, v;
  
  query_t(int _l, int _r, int _lca, int _idx, int _u, int _v):
    l(_l), r(_r), lca(_lca), idx(_idx), u(_u), v(_v) {}

  bool operator < (const query_t& o) const {
    // if(l / BLK != o.l / BLK) {
    //   return l < o.l;
    // }
    // return ((l / BLK) & 1) ? (r < o.r) : (r > o.r);
    if(blk[l] != blk[o.l]) {
      return blk[l] < blk[o.l];
    }
    return (blk[l] & 1) ? (r < o.r) : (r > o.r);
  }
};

struct linked_list_node {
  int val, prev, next;
};

struct linked_list {
  linked_list_node nodes[MxC];
  int head[MxG];

  void insert(int c, int p) {
    if(p == 0) {
      return ;
    }
    int prev_head = head[p];
    nodes[c].val = c;
    nodes[c].next = prev_head;
    nodes[c].prev = 0;
    if(prev_head != 0) {
      nodes[prev_head].prev = c;
    }
    head[p] = c;
  }

  void erase(int c, int p) {
    if(p == 0) {
      return ;
    }
    int pv = nodes[c].prev, n = nodes[c].next;
    if(pv != 0) {
      nodes[pv].next = n;
    }
    else {
      head[p] = n;
    }
    if(n != 0) {
      nodes[n].prev = pv;
    }
  }

  int get_head(int p) {
    return head[p];
  }
};

struct MO_DS {
  int in_path[MxN], freq[MxC], cnt_freq[MxG], distinct_cnt, max_freq;
  linked_list ls;

  MO_DS() {
    distinct_cnt = 0;
    max_freq = 0;
    cnt_freq[0] = MxC;
  }

  void add(int c) {
    ls.erase(c, freq[c]);
    cnt_freq[freq[c]]--;
    if(++freq[c] == 1) {
      distinct_cnt++;
    }
    cnt_freq[freq[c]]++;
    ls.insert(c, freq[c]);
    if(freq[c] > max_freq) {
      max_freq = freq[c];
    }
  }

  void remove(int c) {
    ls.erase(c, freq[c]);
    if(freq[c] == max_freq && cnt_freq[max_freq] == 1) {
      max_freq--;
    }

    cnt_freq[freq[c]]--;
    if(--freq[c] == 0) {
      distinct_cnt--;
    }
    cnt_freq[freq[c]]++;
    ls.insert(c, freq[c]);
  }

  void toggle(int u, const std::vector<int>& a) {
    for(auto c: a) {
      if(in_path[u]) {
        remove(c);
      }
      else {
        add(c);
      }
    }
    in_path[u] ^= 1;
  }
} mo;

std::vector<int> adj[MxN];
std::vector<query_t> queries;
int level[MxN], lift[LG][MxN], tin[MxN], tout[MxN], disc[2 * MxN], timer;

void euler_tour(int u, int p) {
  level[u] = level[p] + 1;
  lift[0][u] = p;

  tin[u] = ++timer;
  disc[timer] = u;
  for(int v: adj[u]) {
    if(v == p) {
      continue;
    }
    euler_tour(v, u);
  }
  tout[u] = ++timer;
  disc[timer] = u;
}

inline int get_lca(int u, int v) {
  if(level[u] < level[v]) {
    std::swap(u, v);
  }
  for(int s=LG-1; s>=0; --s) {
    if(level[lift[s][u]] >= level[v]) {
      u = lift[s][u];
    }
  }
  if(u == v) {
    return u;
  }
  for(int s=LG-1; s>=0; --s) {
    if(lift[s][u] != lift[s][v]) {
      u = lift[s][u];
      v = lift[s][v];
    }
  }
  return lift[0][u];
}

void solve(int N, int Q, std::vector<int> U, std::vector<int> V, std::vector<std::vector<int>> A, std::vector<int> X, std::vector<int> Y, std::vector<int>& ans_distinct, std::vector<int>& ans_mode) {
  for(int i=1; i<N; ++i) {
    int u = U[i-1] + 1, v = V[i-1] + 1;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  for(auto &a: A) {
    for(auto &c: a) {
      c++;
    }
  }
  euler_tour(1, 0);
  long long all_s = 0;
  for(int i=1; i<=N; ++i) {
    all_s += (long long)A[i-1].size();
  }
  int T = 1;
  long long x = 2 * all_s; 
  while ((long long)T * T < x) T++; 
  
  int cw = 0, nb = 0;
  for (int i = 1; i <= 2 * N; i++) {
    int w = A[disc[i] - 1].size();
    if (w > 2 * T) {
      if (cw > 0) { nb++; cw = 0; }
      blk[i] = nb++;
    } else if (cw > 0 && cw + w > 2 * T) {
      nb++; blk[i] = nb; cw = w;
    } else {
      blk[i] = nb; cw += w;
    }
  }
  for(int s=1; s<LG; ++s) {
    for(int i=1; i<=N; ++i) {
      lift[s][i] = lift[s-1][lift[s-1][i]];
    }
  }
  for(int i=0; i<Q; ++i) {
    int u = X[i] + 1, v = Y[i] + 1;
    if(tin[u] > tin[v]) {
      std::swap(u, v);
    }
    int lca = get_lca(u, v);
    if(lca == u) {
      queries.emplace_back(tin[u], tin[v], -1, i, u, v);
    }
    else {
      queries.emplace_back(tout[u], tin[v], lca, i, u, v);
    }
  }
  std::sort(queries.begin(), queries.end());
  int cur_l = 1, cur_r = 0;
  for(auto [l, r, lca, idx, u, v]: queries) {
    while(cur_l > l) {
      cur_l--;
      mo.toggle(disc[cur_l], A[disc[cur_l] - 1]);
    }
    while(cur_r < r) {
      cur_r++;
      mo.toggle(disc[cur_r], A[disc[cur_r] - 1]);
    }
    while(cur_l < l) {
      mo.toggle(disc[cur_l], A[disc[cur_l] - 1]);
      cur_l++; 
    }
    while(cur_r > r) {
      mo.toggle(disc[cur_r], A[disc[cur_r] - 1]);
      cur_r--;
    }
    if(lca != -1) {
      mo.toggle(lca, A[lca - 1]);
    }
    ans_distinct[idx] = mo.distinct_cnt;
    ans_mode[idx] = mo.max_freq > 0 ? mo.ls.get_head(mo.max_freq) - 1 : 0;
    if(lca != -1) {
      mo.toggle(lca, A[lca - 1]);
    }
  }
}
