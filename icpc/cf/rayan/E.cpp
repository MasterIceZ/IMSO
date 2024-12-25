#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    if(n % 2 == 1) {
      if(n == k) {
        cout << "YES";
        deque<int> perm;
        for(int i=1; i<=n; ++i) {
          perm.emplace_back(i);
        }
        for(int j=1; j<=n; ++j) {
          for(int i=1; i<=n; ++i) {
            cout << perm[i] << " ";
          }
          int fr = perm.front();
          perm.pop_front();
          perm.emplace_back(fr);
        }
      }
      else {
        cout << "NO";
      }
      cout << "\n";
    }
    else {
      deque<int> perm;
      for(int i=1; i<=n; ++i) {
        perm.emplace_back(i);
      }
      cout << "YES\n";
      for(int state=1; state<=k; state+=2) {
        for(int i=1; i<=n; ++i) {
          cout << perm[i] << " ";
        }
        cout << "\n";
        for(int i=1; i<=n; ++i) {
          cout << n + 1 - perm[i] << " ";
        }
        cout << "\n";
        int fr = perm.front();
        perm.pop_front();
        perm.emplace_back(fr);
      }
    }
  }
  return 0;
}