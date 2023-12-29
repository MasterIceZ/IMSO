#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int n, i;
  string s, answer;
  cin >> n >> s;
  s = " " + s;
  for(i=1; i<n; ++i) {
    if(s[i] == 'a' || s[i] == 'e') {
      continue;
    }
    if(s[i + 1] == 'a' || s[i + 1] == 'e') {
      answer += s[i];
      answer += s[i + 1];
      answer += ".";
      i++;
    } else {
      answer[answer.size() - 1] = s[i];
      answer += ".";
    }
  }
  if(i <= n) {
    answer[answer.size() - 1] = s[i];
  } else {
    answer.pop_back();
  }
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