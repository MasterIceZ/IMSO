#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

ll a[3][MxN], sum[3][MxN];

inline void solve() {
  int n;
  cin >> n;
  for(int state=0; state<3; ++state) {
    for(int i=1; i<=n; ++i) {
      cin >> a[state][i];
      sum[state][i] = sum[state][i - 1] + a[state][i];
    }
  }
  ll tot = (sum[0][n] - 1ll) / 3ll + 1ll;
  vector<int> people = {0, 1, 2};
  do {
    vector<pair<int, int>> res(3);
    int first_r = 1;
    for(; first_r<=n && sum[people[0]][first_r] < tot; ++first_r);
    res[people[0]] = make_pair(1, first_r);
    for(int middle=first_r+1; middle<=n; ++middle) {
      if(sum[people[1]][middle] - sum[people[1]][first_r] < tot || sum[people[2]][n] - sum[people[2]][middle] < tot) {
        continue;
      }
      res[people[1]] = make_pair(first_r + 1, middle);
      res[people[2]] = make_pair(middle + 1, n);
      for(auto [f, s]: res) {
        cout << f << " " << s << " ";
      }
      cout << "\n";
      return ;
    }
  } while(next_permutation(people.begin(), people.end()));
  cout << "-1\n";
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