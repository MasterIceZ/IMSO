#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    int answer = 4, last = 1;
    for(auto x: s) {
      int cur = x - '0';
      cur = (cur == 0 ? 10: cur);
      int moving = abs(cur - last);
      answer += moving;
      last = cur;
    }
    cout << answer << "\n";
  }
  return 0;
}