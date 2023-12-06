#include <bits/stdc++.h>

using namespace std;

int c[30];

inline void solve() {
  for(int i=0; i<30; ++i) {
    c[i] = 0;
  }
  int n;
  string s;
  cin >> n >> s;
  for(auto x: s) {
    c[x - 'a']++;
  }
  int answer = n;
  sort(c, c + 26, greater<int>());
  for(int i=0; i<26; ++i) {
    if(c[i] == 0) {
      continue;
    }
    for(int j=0; j<26; ++j) {
      if(i == j || c[j] == 0) {
        continue;
      }
      int t = min(c[i], c[j]);
      cerr << "removing " << c[i] << " " << c[j] << "\n";
      answer -= 2 * t;
      c[i] -= t;
      c[j] -= t;
      if(c[i] == 0) {
        break;
      }
    }
  }
  cout << answer;
  cerr << "----\n";
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