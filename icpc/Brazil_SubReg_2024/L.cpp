#include<bits/stdc++.h>

using namespace std;

const int MxN = 100010;
const int MxB = 33;

int cnt[MxB], a[MxN];

void add_bit(int x) {
  for(int i=0; i<=30; ++i) {
    cnt[i] += ((x & (1 << i)) != 0);
  }
}

int get_bit() {
  int res = 0;
  for(int i=30; i>=0; --i) {
    if(cnt[i] == 0) {
      continue;
    }
    res |= (1 << i);
    cnt[i]--;
  }
  return res;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    add_bit(a[i]);
  }
  for(int i=1; i<=n; ++i) {
    cout << get_bit() << " ";
  }
  cout << "\n";
  return 0;
}