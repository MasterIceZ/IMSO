#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MxN = 110;

struct p_t {
  int i, j, v, pri;
  bool operator < (const p_t& o) const {
    return pri > o.pri;
  }
};

int n, m;
char a[MxN][MxN];
priority_queue<p_t> pq;

const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for(int i=1; i<=2*n+1; ++i) {
    for(int j=1; j<=2*m+1; ++j) {
      char v;
      cin >> v;
      a[i][j] = v;
      if(a[i][j] != '.') {
        pq.emplace(i, j, v - '0', v == '8' || v == '3' || v == '5');
      }
    }
  }
  while(!pq.empty()) {
    p_t now = pq.top(); pq.pop();
    if(now.v == '8' || now.v == '3' || now.v == '5') {
      for(int k=0; k<8; ++k) {
        int ii = di[k] + now.i;
        int jj = dj[k] + now.j;
        if(ii < 1 || jj < 1 || ii > 2 * n + 1 || j > 2 * m + 1) {
          continue;
        }
        a[ii][jj] = '.';
      }
    }
    else {
      
    }
  }
  for(int i=1; i<=2*n+1; ++i) {
    for(int j=1; j<=2*m+1; ++j) {
      cout << (char) a[i][j];
    }
    cout << "\n";
  }
}