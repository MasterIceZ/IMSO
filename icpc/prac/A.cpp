#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int t = 0, d = 0;
  for(auto x: s) {
    t += (x == 'T');
    d += (x == 'D');
  }
  cout << (t > d ? "T1": "DRX") << "\n";
  return 0;
}