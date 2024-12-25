#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;
const int INF = 1e9 + 100;

struct segment_tree {
  int t[MxN << 2];
  void update(int l, int r, int id, int v, int idx) {
    if(l > r || l > id || r < id) {
      return ;
    }
    if(l == r) {
      t[idx] = v;
      return ;
    }
    int mid = (l + r) >> 1;
    update(l, mid, id, v, idx << 1);
    update(mid + 1, r, id, v, idx << 1 | 1);
    t[idx] = max(t[idx << 1], t[idx << 1 | 1]);
  }
  int query(int l, int r, int wl, int wr, int idx) {
    if(l > r || l > wr || r < wl) {
      return -INF;
    }
    if(wl <= l && r <= wr) {
      return t[idx];
    }
    int mid = (l + r) >> 1;
    return max(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
  }
};

int a[MxN], mem[MxN], answer[MxN];
vector<pair<int, int>> query[MxN];
segment_tree seg;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, q;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  cin >> q;
  for(int i=1, l, r; i<=q; ++i) {
    cin >> l >> r;
    query[r].emplace_back(l, i);
  }
  for(int i=1; i<=n; ++i) {
    for(ll divisor=1ll; divisor*divisor<=(ll) a[i]; ++divisor) {
      if(((ll) a[i]) % divisor != 0ll) {
        continue;
      }
      seg.update(1, MxN, divisor, mem[divisor], 1);
      mem[divisor] = i;
      if(divisor * divisor == a[i]) {
        break;
      }
      seg.update(1, MxN, a[i] / divisor, mem[a[i] / divisor], 1);
      mem[a[i] / divisor] = i;
    }
    for(auto [ql, idx]: query[i]) {
      ll l = 1, r = MxN;
      while(l < r) {
        int mid = (l + r) >> 1;
        if(seg.query(1, MxN, mid, MxN, 1) >= ql) {
          l = mid + 1;
        }
        else {
          r = mid;
        }
      }
      answer[idx] = l;
    }
  }
  for(int i=1; i<=q; ++i) {
    cout << answer[i]-1 << "\n";
  }
  return 0;
}