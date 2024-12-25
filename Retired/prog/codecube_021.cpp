// sqrt decom

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 20020;
const int SQRT = 144;

int a[MxN];
vector<int> cluster[SQRT];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    cluster[i / SQRT].emplace_back(a[i]);
  }
  for(int i=0; i<SQRT; ++i) {
    sort(cluster[i].begin(), cluster[i].end());
  }
  for(int i=1, stp, edp, l, r; i<=q; ++i) {
    cin >> stp >> edp >> l >> r;
    int answer = 0;
    for(int p=stp; p<=edp; ) {
      if(p % SQRT == 0 && p + SQRT - 1 <= edp) {
        int cluster_idx = p / SQRT;
        auto ub = upper_bound(cluster[cluster_idx].begin(), cluster[cluster_idx].end(), r);
        auto lb = lower_bound(cluster[cluster_idx].begin(), cluster[cluster_idx].end(), l);
        answer += ub - lb;
        p += SQRT;
      }
      else {
        answer += (l <= a[p] && a[p] <= r);
        p += 1;
      }
    }
    cout << answer << " ";
  }
  return 0;
}