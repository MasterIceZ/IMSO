#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1e7 + 10;

bitset<MxN> visited;

bool is_prime(ll n) {
  if(n <= 1) {
    return false;
  }
  if(n <= 3) {
    return true;
  }
  if(n % 2ll == 0ll || n % 3ll == 0ll) {
    return false;
  }
  for(ll i=5; i*i<=n; i+=6) {
    if(n % i == 0 || n % (i + 2ll) == 0ll) {
      return false;
    }
  }
  return true;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, k1, q, x;
  cin >> n >> k1 >> q;
  vector<int> p1, p2;
  if(2 >= k1) {
    p1.emplace_back(2);
  }
  else {
    p2.emplace_back(2);
  }
  for(ll i=3; i<=(ll) n; i+=2) {
    if(visited[i]) {
      continue;
    }
    if(i >= k1) {
      p1.emplace_back(i);
    }
    else {
      p2.emplace_back(i);
    }
    for(ll j=i*i; j<=(ll) n; j+=i) {
      visited[j] = true;
    }
  }
  while(q--) {
    cin >> x;
    if(!is_prime(x)) {
      cout << "-1";
    }
    else {
      if(x >= k1) {
        cout << lower_bound(p1.begin(), p1.end(), x) - p1.begin() + 1;
      }
      else {
        cout << 1 + p1.size() + (lower_bound(p2.begin(), p2.end(), x) - p2.begin());
      }
    }
    cout << "\n";
  }
  
  return 0;
}