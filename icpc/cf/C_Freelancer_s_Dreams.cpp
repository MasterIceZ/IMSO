#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;
const long double EPS = 1e-9;

long double p, q, a[MxN], b[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n >> p >> q;
  for(int i=1; i<=n; ++i) {
    cin >> a[i] >> b[i];
  }
  long double l = 0, r = 1;
  for(int i=1; i<=n; ++i) {
    r = min(r, 1.0 / a[i]);
  }
  auto cal = [&](double x) {
    long double y = q;
    for(int i=1; i<=n; ++i) {
      y = min(y, (1.0 - x * a[i]) / b[i]);
    }
    return x * p + y * q;
  };
  while(r - l > EPS) {
    double mid_1 = l + (r - l) / 3;
    double mid_2 = r - (r - l) / 3;
    if(cal(mid_1) < cal(mid_2)) {
      l = mid_1;
    }
    else {
      r = mid_2;
    }
  }
  cout << fixed << setprecision(12) << cal((l + r) / 2) << "\n";
  return 0;
}