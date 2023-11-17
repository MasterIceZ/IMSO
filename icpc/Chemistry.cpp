#include <bits/stdc++.h>

using namespace std;

const int MxN = 33;
int state[MxN];

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    string s;
    int n, k;
    cin >> n >> k >> s;
    for(auto x: s) {
      state[x - 'a'] = !state[x - 'a'];
    }
    int sum = accumulate(state, state+26, 0);
    if(sum <= k + 1) {
      cout << "YES";
    }
    else {
      cout << "NO";
    }
    cout << "\n";
    for(auto x: s) {
      state[x - 'a'] = 0;
    }
  }
  return 0;
}