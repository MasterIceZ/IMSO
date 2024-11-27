#include <bits/stdc++.h>

using namespace std;

int pw[22];
vector<pair<int, int>> ps;

inline bool ok(string s, string t) {
  int real_val = 0;
  for(int i=(int) t.size()-1, p=0; i>=0; --i, ++p) {
    real_val += (t[i] - '0') * pw[p];
  }
  int remains = 0;
  for(int i=(int) s.size()-1, p=1; i>=0; --i, p=(p+p) % real_val) {
    remains = (remains + (((s[i] - '0') * p) % real_val)) % real_val;
  }
  return remains == 0;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  pw[0] = 1;
  for(int i=1; i<20; ++i) {
    pw[i] = pw[i - 1] * 2;
  }
  string s, t;
  cin >> s >> t;
  for(int i=0; i<(int) s.size(); ++i) {
    if(s[i] != '*') {
      continue;
    }
    ps.emplace_back(0, i);
  }
  for(int i=0; i<(int) t.size(); ++i) {
    if(t[i] != '*') {
      continue;
    }
    ps.emplace_back(1, i);
  }
  int sz = (int) ps.size();
  int max_mask = (1 << sz) - 1;
  for(int mask=0; mask<=max_mask; ++mask) {
    string cur_s = s, cur_t = t;
    auto make_char = [&](int bit) {
      if(ps[bit].first == 0) {
        cur_s[ps[bit].second] = '0' + ((mask & (1 << bit)) != 0);
      }
      else {
        cur_t[ps[bit].second] = '0' + ((mask & (1 << bit)) != 0);
      }
    };
    for(int bit=0; bit<sz; ++bit) {
      make_char(bit);
    }
    if(ok(cur_s, cur_t)) {
      cout << cur_s << "\n";
      return 0;
    }
  }
  return 0;
}