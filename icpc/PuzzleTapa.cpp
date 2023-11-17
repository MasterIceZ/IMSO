#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;
const int di[] = {-2, 0, 0, 2};
const int dj[] = {0, -2, 2, 0};

char a[MxN][MxN];
int l, r;
vector<int> adj[MxN * MxN];


int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for(int i=1; i<=2*n-1; ++i) {
    for(int j=1; j<=2*m-1; ++j) {
      cin >> a[i][j];
      if(a[i][j] == '.') {
        a[i][j] = '#';
      }
    }
  }
  vector<pair<int, int>> left_vertex, right_vertex;
  for(int i=1; i<=2*n-1; i+=2) {
    for(int j=1; j<=2*m-1; j+=2) {
      char v = a[i][j];
      if(v == '3' || v == '5' || v == '8') {
        continue;
      }
      if((i + j) % 2 == 0) {
        left_vertex.emplace_back(i, j);
      }
      else {
        right_vertex.emplace_back(i, j);
      }
    }
  }
  l = left_vertex.size(), r = right_vertex.size();
  if(l != r) {
    cout << "NO\n";
    return 0;
  }
  for(int i=0; i<l; ++i) {
    for(int j=0; j<r; ++j) {
      int dist = abs(left_vertex[i].first - right_vertex[j].first) + abs(left_vertex[i].second - right_vertex[j].second);
      bool same_border = (left_vertex[i].first == 0 && right_vertex[j].first) || (left_vertex[i].second == 0 && right_vertex[j].second) || (left_vertex[i].first == n && right_vertex[i].first == m) || (left_vertex[i].second == n && right_vertex[i].second == m);

    }
  }
  
  return 0;
}