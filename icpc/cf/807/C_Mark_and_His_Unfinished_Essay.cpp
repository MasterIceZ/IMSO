#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxC = 44;

ll l[MxC], r[MxC], jmp[MxC];

inline void solve() {
  int n, c, q;
  string s;
  cin >> n >> c >> q >> s;
  s = " " + s;
  l[0] = 1;
  r[0] = n + 1;
  for(int i=1; i<=c; ++i) {
    ll l, r;
    cin >> l >> r;
    ll cur_size = r - l + 1ll;
    ::l[i] = ::r[i - 1];
    ::r[i] = ::l[i] + cur_size;
    jmp[i] = ::l[i] - l;
  }

  while(q--) {
    ll p;
    cin >> p;
    for(int i=c; i>=1; --i) {
      if(p >= l[i]) {
        p -= jmp[i];
      }
    }
    cout << s[p] << "\n";
  }

  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}