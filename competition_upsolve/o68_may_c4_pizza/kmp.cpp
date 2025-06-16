#include <bits/stdc++.h>

#include "pizza.h"
using namespace std;

using ll = long long;

// Build the KMP “failure” table for a pattern of pairs
static vector<int> build_pi(const vector<pair<ll, ll>> &pat) {
  int n = pat.size();
  vector<int> pi(n, 0);
  for (int i = 1, j = 0; i < n; i++) {
    while (j > 0 && pat[i] != pat[j]) j = pi[j - 1];
    if (pat[i] == pat[j]) ++j;
    pi[i] = j;
  }
  return pi;
}

// Return the minimal circular period of pts in O(N) via KMP
int min_period(const vector<pair<ll, ll>> &pts) {
  int n = pts.size();
  auto pi = build_pi(pts);

  // Scan through “text” = pts[1..] + pts[0..n-2], looking for a full match
  int j = 0;
  for (int i = 1; i < 2 * n - 1; i++) {
    const auto &cur = pts[i % n];
    while (j > 0 && cur != pts[j]) j = pi[j - 1];
    if (cur == pts[j]) ++j;
    if (j == n) return i - n + 1;
  }
  return n;
}

int countangles(int M, vector<int> n, vector<int> a) {
  // 1) sort points by angle
  vector<pair<int, int>> pts(M);
  for (int i = 0; i < M; i++) pts[i] = {a[i], n[i]};
  sort(pts.begin(), pts.end(), [](auto &u, auto &v) {
    return 1ll * u.first * v.second < 1ll * v.first * u.second;
  });

  // 2) build the diff-sequence around the circle
  vector<pair<ll, ll>> diffs;
  diffs.reserve(M);
  auto last = pts.back();
  for (auto &p : pts) {
    ll nu = 1ll * p.first * last.second - 1ll * last.first * p.second;
    ll de = 1ll * last.second * p.second;
    if (nu < 0) nu += de;
    ll g = gcd(nu, de);
    diffs.emplace_back(nu / g, de / g);
    last = p;
  }

  // 3) find minimal rotational period in O(N)
  int period = min_period(diffs);

  // 4) compute the step between pts[period-1] and pts.back(), then invert
  auto &P = pts[period - 1];
  auto &Q = pts.back();
  ll nu = 1ll * P.first * Q.second - 1ll * Q.first * P.second +
          1ll * Q.second * P.second;
  ll de = 1ll * Q.second * P.second;
  ll g = gcd(nu, de);
  nu /= g;
  de /= g;
  // by construction de % nu == 0
  return (de / nu) % 1000000007;
}
