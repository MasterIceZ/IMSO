#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int a[MxN], pref_sum[MxN];

struct segment_tree {
  int t[MxN << 2];
  void build(int l, int r, int idx, int* arr) {
    if(l == r) {
      t[idx] = arr[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx << 1, arr);
    build(mid + 1, r, idx << 1 | 1, arr);
    t[idx] = max(t[idx << 1], t[idx << 1 | 1]);
  }
  int query(int l, int r, int wl, int wr, int idx) {
    if(l > r || l > wr || r < wl) {
      return -1e9 - 100;
    }
    if(wl <= l && r <= wr) {
      return t[idx];
    }
    int mid = (l + r) >> 1;
    return max(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
  }
} seg;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    pref_sum[i] = pref_sum[i - 1] - a[i];
  }
  seg.build(0, n, 1, pref_sum);
  int answer = 0;
  deque<int> dq;
  for(int i=1; i<=n; ++i) {
    while(!dq.empty() && a[dq.back()] <= a[i]) {
      dq.pop_back();
    }
    dq.emplace_back(i);
    answer = max(answer, -pref_sum[i] + seg.query(0, n, 0, i - 1, 1) - a[dq.front()]);
    for(int j=1; j<(int) dq.size(); ++j) {
      answer = max(answer, -pref_sum[i] + seg.query(0, n, dq[j - 1], i - 1, 1) - a[dq[j]]);
    }
  }
  cout << answer << "\n";
  return 0;
}