#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> lis;
  for(int i=1, x; i<=n; ++i) {
    cin >> x;
    int it = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
    if(it == (int) lis.size()) {
      lis.emplace_back(x);
    }
    lis[it] = x;
  }
  cout << lis.size() <<"\n";
  return 0;
}