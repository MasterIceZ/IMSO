#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;

int a[MxN], dp[MxN][MxN * MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  int sum = accumulate(a + 1, a + n + 1, 0);
  if(sum % 2 == 1) {
    cout << "-1\n";
    return 0;
  }
  sort(a + 1, a + n + 1);
  sum >>= 1;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=sum; ++j) {
      if(j == a[i]) {
        dp[i][j] = i;
        continue;
      }
      if(dp[i - 1][j] != 0) {
        dp[i][j] = dp[i - 1][j];
      }
      if(a[i] < j && dp[i - 1][j - a[i]]) {
        dp[i][j] = i;
      }
    }
  }
  if(dp[n][sum] == 0) {
    cout << "-1\n";
    return 0;
  }
  int cur = dp[n][sum];
  set<int> st;
  st.emplace(cur);
  vector<int> v;
  while(sum != 0) {
    v.emplace_back(a[cur]);
    sum -= a[cur];
    cur = dp[cur - 1][sum];
    if(sum != 0) {
      st.emplace(cur);
    }
  }
  vector<int> w;
  for(int i=1; i<=n; ++i) {
    if(st.count(i)) {
      continue;
    }
    w.emplace_back(a[i]);
  }
  sort(v.begin(), v.end());
  sort(w.begin(), w.end());
  int cur_i = 0, cur_j = 0, sum_v = 0, sum_w = 0;
  while(cur_i < (int) v.size() || cur_j < (int) w.size()) {
    if(sum_v <= sum_w) {
      sum_v += v[cur_i];
      cout << v[cur_i];
      cur_i += 1;
    }
    else {
      sum_w += w[cur_j];
      cout << w[cur_j];
      cur_j += 1;
    }
    cout << " ";
  }
  cout << "\n";
  return 0;
}