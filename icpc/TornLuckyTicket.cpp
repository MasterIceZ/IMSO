#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;
const int MxSzA = 7;
string s[MxN];
long long dp[MxSzA][MxN];

bool compareString(const string a, const string b) {
  return a.size() < b.size();
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  int n;
  long long res = 0ll;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> s[i];
  }
  sort(s + 1, s + n + 1, compareString);
  for(int i=1; i<=n; ++i) {
    for(int middle=0; middle<=(int) s[i].size(); ++middle) {
      int front_sum = 0, back_sum = 0;
      // (0 -> middle - 1), (middle -> n - 1)
      for(int c=0; c<(int) s[i].size(); ++c) {
        if(c < middle) {
          front_sum += (s[i][c] - '0');
        }
        else {
          back_sum += (s[i][c] - '0');
        }
      }
      int n_front = middle, n_back = ((int) s[i].size()) - middle;
      if(n_front <= n_back && front_sum <= back_sum) {
        res = res + dp[n_back - n_front][back_sum - front_sum];
      }
      else if(n_front >= n_back && front_sum >= back_sum) {
        res = res  + dp[n_front - n_back][front_sum - back_sum];
      }
      if(middle == 0) {
        dp[(int) s[i].size()][back_sum] += 1ll;
      }
    }
  }
  cout << res << "\n";

  return 0;
}