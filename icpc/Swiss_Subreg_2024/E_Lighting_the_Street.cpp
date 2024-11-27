#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int p[MxN], l[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, L;
  cin >> n >> m >> L;
  for(int i=1; i<=n; ++i) {
    cin >> p[i];
  }
  for(int i=1; i<=m; ++i) {
    cin >> l[i];
  }
  sort(p + 1, p + n + 1);
  sort(l + 1, l + m + 1);
  int lb = 1, rb = m;
  auto ok = [&](int mid) {
    if(p[1] > l[mid]) {
      return false;
    }
    int can_go = p[1] + l[mid];
    for(int i=2; i<=n; ++i) {
      if(p[i] - l[mid] > can_go) {
        return false;
      }
      can_go = p[i] + l[mid];
    }
    return can_go >= L;
  };
  while(lb < rb) {
    int mid = (lb + rb) / 2;
    if(ok(mid)) {
      rb = mid;
    }
    else {
      lb = mid + 1;
    }
  }
  cout << (ok(lb) ? l[lb] : -1) << "\n";
  return 0;
}