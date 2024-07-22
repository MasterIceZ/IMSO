#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

int up[MxN], down[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, h;
  cin >> n >> h;
  n /= 2;
  for(int i=1; i<=n; ++i) {
    cin >> up[i] >> down[i];
  }
  sort(up + 1, up + n + 1);
  sort(down + 1, down + n + 1);
  int cnt = 0, answer = 1e9 + 100;
  for(int i=1; i<=h; ++i) {
    int up_idx = lower_bound(up + 1, up + n + 1, i) - (up + 1);
    int down_idx = upper_bound(down + 1, down + n + 1, h - i) - (down + 1);
    int remain_up = n - up_idx;
    int remain_down = n - down_idx;
    int all_remain = remain_up + remain_down;
    if(all_remain < answer) {
      answer = all_remain;
      cnt = 0;
    }
    if(all_remain == answer) {
      cnt++;
    }
  }
  cout << answer << " " << cnt << "\n";
  return 0;
}