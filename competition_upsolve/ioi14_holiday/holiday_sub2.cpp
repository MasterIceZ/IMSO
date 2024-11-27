#include <bits/stdc++.h>
#include"holiday.h"

using namespace std;
using ll = long long;

const int MxN = 100010;

ll a[MxN];
priority_queue<ll, vector<ll>, greater<ll>> pq;

inline ll remove() {
  ll res = 0ll;
  res += pq.top(); pq.pop();
  res += pq.top(); pq.pop();
  return res;
}

long long findMaxAttraction(int n, int start, int d, int attraction[]) {
  if(d == 0) {
    return 0ll;
  }
  for(int i=1; i<=n; ++i) {
    a[i] = attraction[i - 1];
  }
  for(int i=2; i<=d; ++i){
    pq.emplace(0);
  }
  ll sum = a[1], answer = a[1];
  pq.emplace(a[1]);
  for(int i=2; i<=n && !pq.empty(); ++i) {
    sum += a[i];
    pq.emplace(a[i]);
    sum -= remove();
    answer = max(answer, sum);
  }
  return answer;
}
