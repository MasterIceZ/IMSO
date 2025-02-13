#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;
const int MxA = 1000010;
const ll MOD = 998244353ll;

int a[MxN];
ll dp[MxA], last_update = -1ll;

vector<int> get_prime_factors(int v) {
  vector<int> primes;
  for(int p=2; p*p<=v; ++p) {
    if(v % p != 0) {
      continue;
    }
    while(v % p == 0) {
      v /= p;
    }
    primes.emplace_back(p);
  }
  if(v != 1) {
    primes.emplace_back(v);
  }
  return primes;
}

void update_dp(vector<int> &factor, ll val) {
  int sz = (int) factor.size();
  int max_mask = (1 << sz) - 1;
  for(int mask=1; mask<=max_mask; ++mask) {
    int idx = 1;
    for(int b=0; b<sz; ++b) {
      if(!(mask & (1 << b))) {
        continue;
      }
      idx *= factor[b];
    }
    dp[idx] = (dp[idx] + val) % MOD;
  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  vector<int> factors;
  factors = get_prime_factors(a[1]);
  update_dp(factors, 1ll);
  for(int i=2; i<=n; ++i) {
    ll to_update = 0ll;
    factors = get_prime_factors(a[i]);
    int sz = (int) factors.size();
    int max_mask = (1 << sz) - 1;
    for(int mask=0; mask<=max_mask; ++mask) {
      int idx = 1ll;
      ll sgn = -1ll;
      for(int b=0; b<sz; ++b) {
        if(!(mask & (1 << b))) {
          continue;
        }
        idx *= (ll) factors[b];
        sgn = -sgn;
      }
      to_update = (to_update + (((sgn * dp[idx]) % MOD) + MOD) % MOD) % MOD;
    }
    update_dp(factors, to_update);
    last_update = to_update;
  }
  cout << last_update << "\n";
  return 0;
}