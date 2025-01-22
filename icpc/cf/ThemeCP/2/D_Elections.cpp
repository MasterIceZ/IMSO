#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

ll a[MxN], pref_sum[MxN], suf_max[MxN];

inline void solve() {
  int n, c, maxx = 0, max_idx = -1;
  cin >> n >> c;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    pref_sum[i] = pref_sum[i - 1] + a[i];

    if(a[i] > maxx) {
      maxx = a[i];
      max_idx = i;
    }
  }
  suf_max[n + 1] = 0;
  for(int i=n; i>=1; --i) {
    suf_max[i] = max(suf_max[i + 1], a[i]);
  }
  vector<int> answer;
  for(int i=1; i<=n; ++i) {
    if(i == max_idx && a[1] + c < a[i]) {
      cout << 0;
    }
    else if(suf_max[i] <= a[i] + pref_sum[i - 1] + c) {
      cout << i - 1;
    }
    else {
      cout << i;
    }
    cout << " ";
  }
  cout << "\n";
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