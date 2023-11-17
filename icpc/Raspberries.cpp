#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

int a[MxN];

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    int n, k, e = 0;
    cin >> n >> k;
    for(int i=1; i<=n; ++i) {
      cin >> a[i];
      e += (a[i] % 2 == 0);
    }
    int answer = k;
    if(k == 4) {
      answer = max(0, 2 - e);
    }
    for(int i=1; i<=n; ++i) {
      answer = min(answer, a[i] % k != 0 ? k - (a[i] % k): 0);
    }
    cout << answer << "\n";
  }
  return 0;
}