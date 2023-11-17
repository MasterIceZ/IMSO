#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t, n, k, cnt;
  cin >> t;
  while(t--) {
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int> (n, 0));
    cnt = 0;
    for(int i=0; i<=n-1; ++i) {
      for(int j=0; j<=n-1; ++j) {
        if(cnt >= k) {
          continue;
        }
        cnt++;
        a[j][(i + j) % n] = 1;
      }
    }
    if(k % n == 0) {
      cout << 0;
    }
    else {
      cout << 2;
    }
    cout << "\n";
    for(int i=0; i<=n-1; ++i) {
      for(int j=0; j<=n-1; ++j) {
        cout << a[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}