#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int a[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, d;
  cin >> n >> d;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int cnt = 1, l = 1;
  for(int r=2; r<=n; ++r) {
    if(a[r] - a[l] <= d) {
      continue;
    }
    cnt++;
    l = r;
  }
  cout << cnt << "\n";
  return 0;
}