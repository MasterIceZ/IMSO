#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

pair<char, ll> cards[MxN];
ll a[MxN], dp[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    string s;
    cin >> s;
    char suite = s[0];
    s.erase(s.begin());
    cards[i] = make_pair(suite, stoll(s));
  }
  vector<char> ord = {'E', 'R', 'S', 'W'};
  int answer = n;
  do {
    for(int i=1; i<=n; ++i) {
      for(int c=0; c<4; ++c) {
        if(ord[c] != cards[i].first) {
          continue;
        }
        a[i] = c * (ll) (1e9) + cards[i].second;
      }
      if(cards[i].first == 'C') {
        a[i] = (ll) 1e18 + cards[i].second;
      }
    }
    int sz = 0;
    for(int i=1; i<=n; ++i) {
      int idx = lower_bound(dp, dp + sz, a[i]) - dp;
      dp[idx] = a[i];
      sz += (idx == sz);
    }
    answer = min(answer, n - sz);
  } while(next_permutation(ord.begin(), ord.end()));
  cout << answer << "\n";
  return 0;
}