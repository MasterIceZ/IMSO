#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  string s;
  cin >> s;
  int idx = s.find('0');
  if(idx == string::npos) {
    cout << "1 " << s.size() << " 1 1\n";
    return ;
  }
  string max_xor(s.size(), '0');
  auto generate_xor = [&](string t) {
    string res(s.size(), '0');
    for(int i=0; i<(int) s.size(); ++i) {
      res[i] = (t[i] != s[i]) + '0';
    }
    return res;
  };
  int sz = (int) s.size() - idx;
  int answer_l = 1, answer_r = (int) s.size();
  for(int l=0; l+sz-1<s.size(); ++l) {
    string t(s.size(), '0');
    int r = l+sz-1;
    for(int pt=(int)s.size()-1, p=r; p>=l; --pt, --p) {
      t[pt] = s[p];
    }
    string cur = generate_xor(t);
    if(cur > max_xor) {
      max_xor = cur;
      answer_l = l + 1;
      answer_r = r + 1;
    }
  }
  cout << "1 " << s.size() << " " << answer_l << " " << answer_r << "\n";
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}