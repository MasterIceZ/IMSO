#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 500050; 

int n, t, a[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> n >> t;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int l=0, r=1e9;
  while(l < r) {
    int mid = (l + r) >> 1;
    if(ok(mid)) {
      l = mid + 1;
    } else {
      
    }
  }
  return 0;
}