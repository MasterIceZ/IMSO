#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll miller_rabin_array[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

unordered_map<ll, bool> is_prime;
ll cnt, answer_range;

ll modmul(ll a, ll b, ll M) {
  ll res = a * b - M * ll(1.L / M * a * b);
  return res + M * (res < 0) - M * (res >= (ll) M);
}

ll modpow(ll b, ll e, ll mod) {
  ll answer = 1;
  for(; e; b=modmul(b, b, mod), e /= 2ll) {
    if(e & 1ll) {
      answer = modmul(answer, b, mod);
    }
  }
  return answer;
}

inline bool miller_rabin(ll n) {
  if(n < 2ll || n % 6 % 4 != 1) {
    return (n | 1ll) == 3ll;
  }
  ll s = __builtin_clzll(n - 1ll);
  ll d = n >> s;
  for(ll a: miller_rabin_array) {
    ll p = modpow(a % n, d, n);
    ll i = s;
    while(p != 1ll && p != n - 1ll && a % n && i--) {
      p = modmul(p, p, n);
    }
    if(p != n && i != s) {
      return false;
    }
  }
  return true;
}

void rec(ll l, ll r) {
  ll cur_range = r - l;
  if(cur_range < answer_range) {
    answer_range = cur_range;
    cnt = 0ll;
  }
  if(cur_range == answer_range) {
    cnt++;
  }
  for(ll x=r; x>l; --x) {
    ll nxt = (l + x) / 2ll;
    if(((l + x) & 1ll) != 0ll || !is_prime[nxt]) {
      continue;
    }
    rec(nxt, r);
    break;
  }
  for(ll x=l; x<r; ++x) {
    ll nxt = (r + x) / 2ll;
    if(((r + x) & 1ll) != 0ll || !is_prime[nxt]) {
      continue;
    }
    rec(l, nxt);
    break;
  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while(q--) {
    ll l, r;
    cin >> l >> r;
    l = 2ll * l;
    r = 2ll * r;
    for(ll i=l; i<=r; ++i) {
      is_prime[i] = miller_rabin(i);
    }
    cnt = 0ll;
    answer_range = 1e18;
    rec(l, r);
    cerr << "! " << answer_range << "\n";
    cout << cnt << "\n";
  }
  return 0;
}