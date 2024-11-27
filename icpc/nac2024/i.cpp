#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MxN = ;

ll pre[MxN], suf[MxN];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s = " " + s;
  for(int i=1; i<=n; ++i) {
    pre[i] = pre[i - 1] + (s[i] == 'N');
  }
  for(int i=n; i>=1; --i) {
    suf[i] = suf[i - 1] + (s[i] == 'C');
  }
  for(int i=1; i<=n; ++i) {
    
  }
  return 0;
}