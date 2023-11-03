#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void runcase() {
  int n, x, a = -100010, b = -100010;
  cin >> n;
  map<int, int> c;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    c[x]++;
  }
  if(c.size() > 2) {
    cout << "No";
    return;
  }
  if(c.size() == 1) {
    cout << "Yes";
    return;
  }
  bool flag = false;
  for (auto it=c.begin(); it!=c.end(); ++it) {
    if(!flag)
      a = it->first;
    else
      b = it->second;
    flag = true;
  }
  return;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while(t--) {
    runcase();
    cout << "\n";
  }
  return 0;
}