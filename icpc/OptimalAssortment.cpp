#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;
const int MxV = 1000010;
const int MMM = 1000000;

struct segment_tree {
  ll tree[MxV << 2];
  void update(int l, int r, int id, int v, int idx) {
    if(l > r || l > idx || r < idx) {
      return ;
    }
    if(l == r) {
      tree[idx] = tree[idx] + v;
      return ;
    }
    int mid = (l + r) >> 1;
    update(l, mid, id, v, idx << 1);
    update(mid + 1, r, id, v, idx << 1 | 1);
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
  }
  ll query(int l, int r, int wl, int wr, int idx) {
    if(l > r || l > wr || r < wl) {
      return ;
    }
    if(wl <= l && r <= wr) {
      return tree[idx];
    }
    int mid = (l + r) >> 1;
    return query(l, mid, wl, wr, idx << 1) + query(mid + 1, r, wl, wr, idx << 1 | 1);
  }
} seg[2];

ll v[MxN], l[MxN], r[MxN];

void queryAnswer() {
  
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    cin >> v[i];
  }
  for(int i=0; i<=n; ++i) {
    cin >> l[i];
  }
  for(int i=0; i<=n; ++i) {
    cin >> r[i];
  }
  for(int i=1; i<=n; ++i) {
    seg[0].update(0, MMM, v[i], l[i], 1);
    seg[1].update(0, MMM, v[i], l[i] * v[i], 1);
  }

  return 0;
}