// #include "cake.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX / 4;

struct Line {
  ll m, b;
  int idx;
};
ll eval(const Line &ln, ll x) { return ln.m * x + ln.b; }

struct LiChao {
  struct Node {
    Line ln;
    Node *l, *r;
    Node(const Line &v) : ln(v), l(nullptr), r(nullptr) {}
  };
  Node *root;
  ll lo, hi;
  LiChao(ll _lo, ll _hi) : root(nullptr), lo(_lo), hi(_hi) {}
  void add_line(const Line &nw) { add_line(root, lo, hi, nw); }
  void add_line(Node *&node, ll l, ll r, Line nw) {
    if (!node) {
      node = new Node(nw);
      return;
    }
    ll mid = (l + r) >> 1;
    if (eval(nw, mid) < eval(node->ln, mid)) swap(nw, node->ln);
    if (l == r) return;
    if (eval(nw, l) < eval(node->ln, l))
      add_line(node->l, l, mid, nw);
    else
      add_line(node->r, mid + 1, r, nw);
  }
  pair<ll, int> query(ll x) const { return query(root, lo, hi, x); }
  pair<ll, int> query(Node *node, ll l, ll r, ll x) const {
    if (!node) return {INF, -1};
    ll cur = eval(node->ln, x);
    pair<ll, int> ans = {cur, node->ln.idx};
    if (l == r) return ans;
    ll mid = (l + r) >> 1;
    if (x <= mid) {
      auto left = query(node->l, l, mid, x);
      if (left.first < ans.first) ans = left;
    } else {
      auto right = query(node->r, mid + 1, r, x);
      if (right.first < ans.first) ans = right;
    }
    return ans;
  }
};

int N, M;
vector<ll> X, Y;

pair<ll, int> solve(ll lambda) {
  cerr << "D: lambda = " << lambda << "\n";
  vector<ll> dp(N, INF);
  vector<int> cnt(N, 0);
  LiChao hull(0, 1000000000LL);
  dp[0] = 0;
  cnt[0] = 0;
  hull.add_line({-X[0], dp[0] + X[0] * Y[0] + lambda, 0});
  for (int i = 1; i < N; i++) {
    auto q = hull.query(Y[i]);
    dp[i] = q.first - X[i] * Y[i];
    cnt[i] = cnt[q.second] + 1;
    hull.add_line({-X[i], dp[i] + X[i] * Y[i] + lambda, i});
  }
  return {dp[N - 1], cnt[N - 1]};
}

ll whipped_cream_price(int N, int M, vector<int> _X, vector<int> _Y) {
  cerr << "D: START!\n";
  for (int i = 0; i < N; i++) {
    X[i] = _X[i];
    Y[i] = _Y[i];
  }

  ll lo = 0, hi = 1e18;
  while (lo < hi) {
    ll mid = lo + (hi - lo) / 2;
    auto res = solve(mid);
    if (res.second > M)
      lo = mid + 1;
    else
      hi = mid;
  }
  auto final_res = solve(lo);
  ll total_cost = final_res.first - lo * M;
  cerr << "D: DONE!\n";
  return total_cost;
}

int main() { 
  cerr << "D: START!\n";
  cout << whipped_cream_price(5, 2, {1, 3, 4, 6, 8}, {2, 3, 5, 9, 10}); 
}