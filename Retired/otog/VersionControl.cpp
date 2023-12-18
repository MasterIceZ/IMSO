#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> oprs;
  for(int i=1; i<=n; ++i) {
    char opr;
    cin >> opr;
    if(opr == 'T') {
      char c;
      cin >> c;
      oprs.emplace_back((int) c);
    }
    else {
      int x;
      cin >> x;
      oprs.emplace_back(-x);
    }
  }
  // reverse(oprs.begin(), oprs.end());
  string answer;
  for(int i=n-1; i>=0; --i) {
    if(oprs[i] < 0) {
      i += oprs[i];
    }
    else {
      answer += ((char) oprs[i]);
    }
  }
  reverse(answer.begin(), answer.end());
  cout << answer << "\n";
  return 0;
}