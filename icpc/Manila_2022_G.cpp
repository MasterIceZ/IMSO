#include <bits/stdc++.h>

using namespace std;

map<int, int> line;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, k, l, r, cnt = 0;
  cin >> n >> k;
  for(int i=1; i<=n; ++i) {
    cin >> l >> r;
    int rr = (r + 1) % k;
    int ll = l % k;
    if(r - l + 1 >= k) {
      cnt += 1;
    }
    else if(rr > ll) {
      line[ll] += 1;
      line[rr] -= 1;
    }
    else {
      line[ll] += 1;
      line[rr] -= 1;
      line[0] += 1;
    }
  }
  int pref_sum = 0, answer = 0;
  for(auto x: line) {
    pref_sum += x.second;
    answer = max(answer, pref_sum);
  }
  cout << cnt + answer << "\n";
  return 0;
}