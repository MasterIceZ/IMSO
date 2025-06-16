#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  // C[0..N]: objective coefficients for white-bag count W
  vector<ll> C(N + 1);
  for (int w = 0; w <= N; w++) {
    cin >> C[w];
  }

  sort(A.begin(), A.end());
  // P[w] = sum of smallest w elements of A
  vector<ll> P(N + 1, 0);
  for (int i = 0; i < N; i++) {
    P[i + 1] = P[i] + A[i];
  }
  ll S = P[N];

  ll ans = LLONG_MIN;
  for (int w = 0; w <= N; w++) {
    int rem = N - w;
    bool ok;
    if (K >= 1) {
      ok = true;
    } else {
      // K == 0: must split rem stones into two equal-size groups
      ok = (rem % 2 == 0);
    }
    if (!ok) continue;
    ll val = C[w] + (S - P[w]);
    ans = max(ans, val);
  }

  cout << ans << "\n";
  return 0;
}