#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

int c[MxN], a[MxN];

void solve() {
  int n;
  cin >> n;
  ll answer = 0ll;
  for(ll l=1, r=1, x; r<=(ll) n; ++r) {
    cin >> a[r];
    c[a[r]]++;
    while(c[a[l]] > 1 && l <= r) {
      c[a[l++]]--;
    }
    cerr << r << ":" << r << " " << l << "\n";
    answer += r - l + 1ll;
  }
  cout << answer;
  for(int i=1; i<=200000; ++i) {
    c[i] = 0;
  }
  return ;
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