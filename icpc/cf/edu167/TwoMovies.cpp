#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

int a[MxN], b[MxN];

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for(int i=1; i<=n; ++i) {
    cin >> b[i];
  }
  int first_good = 0, second_good = 0, good = 0, bad = 0;
  for(int i=1; i<=n; ++i) {
    first_good += (a[i] > b[i] ? a[i]: 0);
    second_good += (b[i] > a[i] ? b[i]: 0);
    if(a[i] == b[i]) {
      good += (a[i] > 0);
      bad += (a[i] < 0);
    }
  }
  int diff = good - bad, answer = -1e9 - 100;
  for(int i=0; i<=bad; ++i) {
    answer = max(answer, min(first_good - i, second_good + diff + i));
  }
  for(int i=0; i<=good; ++i) {
    answer = max(answer, min(first_good + i, second_good + diff - i));
  }
  cout << answer << "\n";
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