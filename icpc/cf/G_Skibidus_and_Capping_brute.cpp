#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;
const pair<int, int> FACTOR_NOT_FOUND = make_pair(-1, -1);

ll cnt_sieve[MxN];
map<int, ll> cnt_local;
int a[MxN];
bool is_prime[MxN], is_semiprime[MxN];
vector<int> all_primes;

pair<int, int> get_factor_semiprime(int v) {
  for(auto p: all_primes) {
    if(v % p == 0) {
      return make_pair(p, v / p);
    }
  }
  return FACTOR_NOT_FOUND;
}

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }

  auto get_lcm = [&](int a, int b) {
    return a * b / __gcd(a, b);
  };
  
  for(int i=1; i<=n; ++i) {
    for(int j=i; j<=n; ++j) {
      if(is_semiprime[get_lcm(a[i], a[j])] == true) {
        cout << "(" << i << ", " << j << "): " << get_lcm(a[i], a[j]) << "\n";
      }
    }
  }
  cout << "----\n";
  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  for(int i=2; i<MxN; ++i) {
    if(cnt_sieve[i] != 0) {
      continue;
    }
    cnt_sieve[i] = 1ll;
    is_prime[i] = true;
    all_primes.emplace_back(i);
    for(int j=i*2; j<MxN; j+=i) {
      cnt_sieve[j] += 1ll;
    }
  }
  for(int i=2; i<MxN; ++i) {
    if(cnt_sieve[i] == 2) {
      is_semiprime[i] = true;
    }
  }
  for(auto p: all_primes) {
    if(p * p > MxN) {
      break;
    }
    is_semiprime[p * p] = true;
  }

  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}

// (2, 3), (2, 3)
// (2, 4), (2, 4)