#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

int a[MxN];

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  int sum = accumulate(a + 1, a + n + 1, 0);
  if(sum % 2 != 0) {
    cout << "-1\n";
    return ;
  }
  vector<pair<int, int>> answer;
  for(int i=1; i<=n; ++i) {
    if(a[i + 1] == 1 && sum > 0) {
      answer.emplace_back(i, i + 1);
      i++;
      sum -= 2;
    }
    else if(a[i + 1] == -1 && sum < 0) {
      answer.emplace_back(i, i + 1);
      i++;
      sum += 2;
    }
    else {
      answer.emplace_back(i, i);
    }
  }
  assert(sum == 0);
  cout << answer.size() << "\n";
  for(auto p: answer) {
    cout << p.first << " " << p.second << "\n";
  }
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