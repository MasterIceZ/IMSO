#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int x[MxN], y[MxN];
ll cnt_x[MxN], cnt_y[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> x[i] >> y[i];
    cnt_x[x[i]]++;
    cnt_y[y[i]]++;
  }
  ll cnt = 0ll;
  for(int i=1; i<=n; ++i) {
    cnt += (cnt_x[x[i]] - 1ll) * (cnt_y[y[i]] - 1ll);
  }
  cout << cnt << "\n";
  return 0;
}