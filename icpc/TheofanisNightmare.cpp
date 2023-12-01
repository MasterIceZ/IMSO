#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

ll a[MxN];

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  ll sum = 0ll, answer = 0ll;
  for(int i=n; i>=1; --i) {
    sum += a[i];
    if(i > 1 && sum > 0) {
      answer += sum;
    }
  }
  answer += sum;
  cout << answer;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}