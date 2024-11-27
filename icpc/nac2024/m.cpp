#include <bits/stdc++.h>

using namespace std;

const int MxN = 5050;

bool visited[MxN][MxN];

signed main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  set<pair<int, int>> st;
  st.emplace(0, 0);
  for(int i=1, alow, ahi, blow, bhi; i<=n; ++i) {
    scanf("%d %d %d %d", &alow, &ahi, &blow, &bhi);
    alow -= a; ahi -= a;
    blow -= b; bhi -= b;
    vector<pair<int, int>> to_consider;
    for(auto [x, y]: st) {
      if(alow <= x && x <= ahi && blow <= y && y <= bhi) {
        to_consider.emplace_back(x, y);
      }
    }
    for(auto [x, y]: to_consider) {
      if(!visited[x + 1][y]) {
        visited[x + 1][y] = true;
        st.emplace(x + 1, y);
      }
      if(!visited[x][y + 1]) {
        visited[x][y + 1] = true;
        st.emplace(x, y + 1);
      }
      st.erase({x, y});
    }
  }
  int answer = 0;
  for(int i=0; i<MxN; ++i) {
    for(int j=0; j<MxN; ++j) {
      if(visited[i][j]) 
        answer = max(answer, i + j);
    }
  }
  cout << answer;
  return 0;
}