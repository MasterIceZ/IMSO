#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &x: a) {
    cin >> x;
  }
  for(int to_size=n-1; to_size>=1; --to_size) {
    vector<int> new_arr;
    for(int i=1; i<(int) a.size(); ++i) {
      int diff = a[i] - a[i - 1];
      if(diff <= 0) {
        continue;
      }
      new_arr.emplace_back(diff);
    }
    assert((int) new_arr.size() <= to_size);
    if(new_arr.size() != to_size) {
      new_arr.emplace_back(0);
    }
    sort(new_arr.begin(), new_arr.end());
    swap(a, new_arr);
  }
  cout << a[0] << "\n";
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