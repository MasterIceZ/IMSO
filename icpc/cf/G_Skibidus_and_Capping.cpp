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
      assert(is_prime[v / p]);
      return make_pair(p, v / p);
    }
  }
  return FACTOR_NOT_FOUND;
}

inline void solve() {
  int n;
  cin >> n;
  ll cnt_primes = 0ll, answer = 0ll;
  vector<int> primes, semiprimes;
  cnt_local.clear();
  for(int i=1; i<=n; ++i) {
    cin >> a[i];

    cnt_local[a[i]]++;
    if(is_prime[a[i]]) {
      primes.emplace_back(a[i]);
      cnt_primes++;
    }
    if(is_semiprime[a[i]]) {
      semiprimes.emplace_back(a[i]);
    }
  }
  
  // case (prime, prime)
  sort(primes.begin(), primes.end());
  primes.resize(unique(primes.begin(), primes.end()) - primes.begin());
  for(auto p: primes) {
    answer += (cnt_local[p] * (cnt_primes - cnt_local[p])) / 2ll;
  }

#ifdef ICY
  cerr << "ANSWER: " << answer << "\n";
#endif

  // case semiprime
  sort(semiprimes.begin(), semiprimes.end());
  semiprimes.resize(unique(semiprimes.begin(), semiprimes.end()) - semiprimes.begin());
  for(auto sp: semiprimes) {
    pair<int, int> factors = get_factor_semiprime(sp);
    assert(factors != FACTOR_NOT_FOUND);

#ifdef ICY
    cerr << "D: " << sp << " " << factors.first << " " << factors.second << "\n";
#endif
    
    // case (semiprime, prime)
    answer += cnt_local[sp] * cnt_local[factors.first];
    answer += cnt_local[sp] * cnt_local[factors.second];
    
    // case (self, self)
    answer += (cnt_local[sp] * (1ll + cnt_local[sp])) / 2ll;
  }

  cout << answer << "\n";
#ifdef ICY
  exit(0);
#endif
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