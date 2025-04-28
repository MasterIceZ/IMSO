#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct slope_trick {
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll answer = 0ll;
  void add_val(ll v) {
    answer -= v;
    pq.emplace(v);
    pq.emplace(v);
    pq.pop();
  }
  ll query() {
    while(!pq.empty()) {
      answer += pq.top();
      pq.pop();
    }
    return answer;
  }
} dp;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1, x; i<=n; ++i) {
    cin >> x;
    dp.add_val(x);
  }
  cout << dp.query() << "\n";
  return 0;
}