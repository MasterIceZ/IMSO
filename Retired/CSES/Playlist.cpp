#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

int a[MxN];
map<int, int> mp;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, l = 1, answer = 0;
  cin >> n;
  for(int r=1; r<=n; ++r) {
    cin >> a[r];
    while(mp[a[r]] != 0) {
      mp[a[l]]--;
      l++;
    }
    mp[a[r]]++;
    answer = max(answer, r - l + 1);
  }
  cout << answer;
  return 0;
}