#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7ll;

inline ll mop(ll a, ll b) {
  ll res = 1ll;
  for(; b>0; a=(a * a) % MOD, b >>= 1ll) {
    if(b & 1ll) {
      res = (res * a) % MOD;
    }
  }
  return res;
}

inline ll inverse_divide(ll x) {
  return mop(x, MOD - 2);
}

inline ll ceil_div(ll a, ll b) {
  return ((a - 1ll) / b + 1ll) % MOD;
}

inline ll floor_div(ll a, ll b) {
  return (a / b) % MOD;
}

void solve() {
  ll n, k, sum_special = 0ll, sum_normal = 0ll;
  cin >> n >> k;
  vector<ll> v(n + 1);
  for(int i=1; i<=n; ++i){
    cin >> v[i];
    if(i <= k) {
      sum_special = (sum_special + v[i]) % MOD;
    }
    else {
      sum_normal = (sum_normal + v[i]) % MOD;
    }
  }
  ll alice_number_special = (((ceil_div(n - k + 1ll, 2ll) * k) % MOD) * inverse_divide(n - k + 1ll)) % MOD;
  ll alice_special_expected = (alice_number_special * ((sum_special * inverse_divide(k)) % MOD)) % MOD;
  ll alice_number_normal = floor_div(n - k + 1ll, 2ll);
  ll alice_normal_expected = (alice_number_normal * ((sum_normal * inverse_divide(n - k)) % MOD)) % MOD;
  ll alice_answer = (alice_special_expected + alice_normal_expected) % MOD;
  ll bob_answer = ((sum_normal + sum_special - alice_answer) % MOD + MOD) % MOD;
  cout << alice_answer << " " << bob_answer << "\n";
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