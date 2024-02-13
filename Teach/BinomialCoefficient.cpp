#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1e7 + 10;

ll m, n, k, fac[MxN], inv[MxN];

ll mul(ll a, ll b) {
  ll r = 1ll;
  a = a % m;
  for(; b>0ll; b = b >> 1ll, a = (a * a) % m) {
    if(b & 1) {
      r = (r * a) % m;
    }
  }
  return r;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t >> m;
  fac[0] = 1ll; inv[0] = mul(fac[0], m - 2ll);
  for(ll i=1; i<=(ll) (1e7); ++i) {
    fac[i] = (fac[i - 1] * i) % m;
    inv[i] = mul(fac[i], m - 2ll);
  }
  // cerr << fac[2] << " " << mul(fac[2], m - 2) << "\n";
  while(t--) {
    cin >> n >> k;
    if(k > n) {
      cout << "0" << "\n";
    }
    else {
      ll x = (fac[n] * inv[n - k]) % m;
      x = (x * inv[k]) % m;
      cout << x << "\n";
    }
  }
  return 0;
}