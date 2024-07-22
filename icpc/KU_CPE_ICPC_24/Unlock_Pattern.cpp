#include <bits/stdc++.h>

using namespace std;
using ll = long long;

double answer;
pair<int, int> pos[10];

double make_dist_2(pair<int, int> a, pair<int, int> b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  for(int i=1; i<=3; ++i) {
    for(int j=1, x; j<=3; ++j) {
      cin >> x;
      pos[x] = make_pair(i, j);
    }
  }
  for(int i=2; i<=9; ++i) {
    double dist_2 = make_dist_2(pos[i], pos[i - 1]);
    answer += sqrt(dist_2);
  }
  cout << fixed << setprecision(10) << answer << "\n";
  return 0;
}