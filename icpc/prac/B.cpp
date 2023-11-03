#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  vector<int> cnt(26);
  for(auto x: s) {
    cnt[x - 'a']++;
  }
  cout << ((int) s.size()) - *max_element(cnt.begin(), cnt.end());
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