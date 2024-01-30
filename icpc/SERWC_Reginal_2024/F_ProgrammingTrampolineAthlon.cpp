#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

pair<ll, pair<int, string>> a[MxN];
ll p;
vector<ll> scores;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i].second.second >> p;
    a[i].second.first = -i;
    vector<ll> e(6);
    for(auto &x: e) {
      cin >> x;
    }
    ll score = (p * 10ll) + accumulate(e.begin(), e.end(), 0ll) - *max_element(e.begin(), e.end()) - *min_element(e.begin(), e.end());
    a[i].first = score;
    scores.emplace_back(score);
  }
  sort(scores.begin(), scores.end());
  scores.resize(unique(scores.begin(), scores.end()) - scores.begin());
  reverse(scores.begin(), scores.end());
  sort(a + 1, a + n + 1, greater<pair<ll, pair<int, string>>> ());
  while((int) scores.size() < 3) {
    scores.emplace_back(0);
  }
  for(int i=1; i<=min(n, 1000); ++i) {
    if(i <= 3 || a[i].first == a[3].first) {
      cout << a[i].second.second << " " << a[i].first << "\n";
    }
  }
  return 0;
}