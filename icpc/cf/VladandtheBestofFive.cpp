#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    int cnt = 0;
    for(auto x: s) {
      cnt += (x == 'A');
    }
    if(cnt > 2) {
      cout << "A";
    } else {
      cout << "B";
    }
    cout << "\n";
  }
  return 0;
}