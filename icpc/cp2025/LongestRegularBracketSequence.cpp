#include <iostream>
#include <stack>
#include <string>

const int MxN = 1000010;

int dp[MxN];

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  int n = (int) s.size(), maxx = 0, cnt = 1;
  s = " " + s;
  std::stack<int> st;
  for(int i=1; i<=n; ++i) {
    if(s[i] == '(') {
      st.emplace(i);
    }
    else {
      if(st.empty()) {
        continue;
      }
      int t = st.top();
      st.pop();
      int len = i - t + 1;
      dp[i] = dp[t - 1] + len;
      if(dp[i] > maxx) {
        maxx = dp[i];
        cnt = 0;
      }
      if(dp[i] == maxx) {
        ++cnt;
      }
    }
  }
  std::cout << maxx << " " << cnt << "\n";
  return 0;
}