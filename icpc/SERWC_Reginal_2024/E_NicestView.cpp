#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using fraction = pair<ll, ll>;

const int MxN = 100010;

ll h[MxN];

vector<fraction> p;

bool compare_fraction(fraction a, fraction b) {
  return a.first * b.second < a.second * b.first;
}

inline fraction calc(ll idx, ll max_index) {
  ll divisor = h[max_index] - h[max_index + 1];
  ll numerator = idx;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> h[i];
  }
  ll current_max = h[1];
  int max_index = 1;
  for(int i=2; i<=n; ++i) {
    
  }
  return 0;
}