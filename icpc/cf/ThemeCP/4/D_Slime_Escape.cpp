#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;
const ll INF = 1e18 + 100ll;

int n, k;
ll a[MxN];

inline bool check() {
  ll sum = 0ll, cur_cost = INF;
  vector<ll> sums, costs;
  for(int i=k+1; i<=n; ++i) {
    sum += a[i];
    cur_cost = min(cur_cost, sum);
    if(a[i] > 0 && sum > 0) {
      sums.emplace_back(sum);
      costs.emplace_back(cur_cost);
      sum = 0ll;
      cur_cost = INF;
    }
  }
  int m = (int) sums.size();
  sum = 0ll;
  for(int i=k, pt=0; i>=1; --i) {
    sum += a[i];
    while(pt < m && sum + costs[pt] >= 0) {
      sum += sums[pt];
      pt++;
    }
    if(sum < 0ll) {
      return false;
    }
  }
  return true;
}

inline void solve() {
  cin >> n >> k;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  bool answer = check();
  k = n - k + 1;
  reverse(a + 1, a + n + 1);
  answer |= check();
  cout << (answer ? "YES": "NO") << "\n";
  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}