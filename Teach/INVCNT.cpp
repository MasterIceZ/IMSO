#include <bits/stdc++.h>

using namespace std;
// using ll = long long;
#define ll long long

const int MxN = 200020;
int a[MxN], b[MxN];
ll cnt;

void merge_sort(int l, int r) {
  if(l == r) {
    return ;
  }
  int mid = (l + r) / 2;
  merge_sort(l, mid);
  merge_sort(mid + 1, r);
  int i = l, j = mid + 1, k = l;
  while(i <= mid && j <= r) {
    if(a[i] <= a[j]) {
      b[k++] = a[i++];
    }
    else {
      cnt += mid - i + 1;
      b[k++] = a[j++];
    }
  }
  while(i <= mid) {
    b[k++] = a[i++];
  }
  while(j <= r) {
    b[k++] = a[j++];
  }
  for(int i=l; i<=r; ++i) {
    a[i] = b[i];
  }
}

void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  cnt = 0ll;
  merge_sort(1, n);
  cout << cnt;
}

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}