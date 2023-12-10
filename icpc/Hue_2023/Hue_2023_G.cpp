#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

int a[MxN << 1];

void solve() {
  int n;
  cin >> n;
  if(n == 0) {
    exit(0);
  }
  for(int i=1; i<=2*n; ++i) {
    cin >> a[i];
  }

  return ;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  while(1) {
    solve();
  }
  return 0;
}