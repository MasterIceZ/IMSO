#include <bits/stdc++.h>
 
using namespace std;
 
const int MxN = 200020;
int a[MxN], n, k;
unordered_map<int, int> c;

inline void update_count() {
  c.clear();
  for(int i=1; i<=n; ++i) {
    c[a[i]] += 1;
  }
  return ;
}
 
int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  bool change = true;
  cin >> n >> k;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  update_count();
  for(int j=1; j<=k && change; ++j) {
    change = false;
    for(int i=1; i<=n; ++i) {
      if(c[a[i]] != a[i]) {
        change = true;
        break;
      }
    }
    for(int i=1; i<=n; ++i) {
      a[i] = c[a[i]];
    }
    update_count();
  }
  for(int i=1; i<=n; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
  return 0;
}