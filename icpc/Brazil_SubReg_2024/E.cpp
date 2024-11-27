#include <bits/stdc++.h>

using namespace std;

const int MxN = 55;

int a[MxN][MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  pair<int, int> max_pos = make_pair(-1, -1);
  int max_val = -1;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      cin >> a[i][j];
      if(a[i][j] > max_val) {
        max_val = a[i][j];
        max_pos = make_pair(i, j);
      }
    }
  }
  if(max_pos == make_pair(n, n)) {
    cout << "0";
  }
  else if(max_pos == make_pair(n, 1)) {
    cout << "1";
  }
  else if(max_pos == make_pair(1, 1)) {
    cout << "2";
  }
  else {
    cout << "3";
  }
  cout << "\n";
  return 0;
}