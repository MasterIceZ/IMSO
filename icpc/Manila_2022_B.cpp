// dp + math (offline)

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxP = 30030;
const int MxN = 2020;
const int MxQ = 100010;
const ll MOD = 1169996969ll;

struct query_t {
  int n;
  ll p, q;
  int i;
  bool operator < (const query_t &o) const {
    return n < o.n;
  }
};

query_t query[MxQ];
vector<int> primes;
bitset<MxP> not_prime;
ll prefix_sum_primes[MxP], answer[MxN];
unordered_map<ll, ll> dp[2];

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  int t = 1, max_n = 0;
  cin >> t;
  for(int i=1; i<=t; ++i){
    cin >> query[i].n >> query[i].p >> query[i].q;
    query[i].i = i;
    max_n = max(max_n, query[i].n);
    int g = __gcd(query[i].p, query[i].q);
    query[i].p = query[i].p / g;
    query[i].q = query[i].q / g;
  }
  sort(query + 1, query + t + 1);

  primes.emplace_back(2);
  for (int i = 3; i < MxP; i += 2) {
    if(not_prime[i]) {
      continue;
    }
    primes.emplace_back(i);
    for (int j = i * i; j < MxP; j += i) {
      not_prime[i] = true;
    }
  }

  for (int i = 0; i<primes.size(); ++i) {
    prefix_sum_primes[i + 1] = prefix_sum_primes[i] + primes[i];
  }

  int idx = 1;
  dp[0][0] = false;
  for (int i = 1; i <= max_n; ++i){
    // calculate
    dp[i & 1].clear();
    for(int j=1; j<=i; ++j) {
      dp[i][prefix_sum_primes[j]]
    }
    // memorize answer
    while (query[idx].n == i) {
      if (prefix_sum_primes[i] % (query[i].p + query[i].q) == 0) {
        answer[query[idx].i] = dp[i % 2][prefix_sum_primes[i] / (query[idx].q + query[idx].p) * query[idx].p];
      }
      idx++;
    }
  }

  for (int i = 1; i <= t; ++i) {
    cout << answer[i] << "\n";
  }
  return 0;
}