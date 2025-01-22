#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 10010;
const ll MOD = 998244353ll;

ll fac[MxN], inv_fac[MxN];
int status[MxN];

inline ll mop(ll a, ll b) {
  ll r = 1ll;
  for(; b>0; b >>= 1ll, a=(a * a) % MOD) {
    if(b & 1ll) {
      r = (r * a) % MOD;
    }
  }
  return r;
}

inline ll C(int n, int r) {
  return (((fac[n] * inv_fac[n - r]) % MOD) * inv_fac[r]) % MOD;
}

inline ll catalan(int n) {
  return (C(2 * n, n) * mop(n + 1, MOD - 2ll)) % MOD;
}

inline void solve() {
  int n;
  cin >> n;
  vector<ll> answer = {catalan(n)};
  for(int i=1; i<=2*n; ++i) {
    status[i] = 0;
  }
  for(int i=1, l, r; i<=n; ++i) {
    cin >> l >> r;
    status[l]++, status[r]--;
    stack<ll> st;
    ll cur_answer = 1ll, c = 0ll;
    for(int j=1; j<=2*n; ++j) {
      if(status[j] == 1) {
        st.emplace(c);
        c = 1;
      }
      else if(status[j] == -1) {
        cur_answer = (cur_answer * catalan((c - 1) / 2)) % MOD;
        c = st.top();
        st.pop();
      }
      else {
        c++;
      }
    }
    cur_answer = (cur_answer * catalan(c / 2)) % MOD;
    answer.emplace_back(cur_answer);
  }
  for(auto e: answer) {
    cout << e << " ";
  }
  cout << "\n";
  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  fac[0] = 1ll;
  for(int i=1; i<MxN; ++i) {
    fac[i] = (fac[i - 1] * i) % MOD;
  }
  inv_fac[MxN - 1] = mop(fac[MxN - 1], MOD - 2ll);
  for(ll i=MxN-2; i>=0; --i) {
    inv_fac[i] = (inv_fac[i + 1] * (i + 1ll)) % MOD;
  }

  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}