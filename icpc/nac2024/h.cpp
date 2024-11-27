#include <bits/stdc++.h>

using namespace std;

using db = double;

const db INF = numeric_limits<db>::max();

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,m,_t;
  cin >> n >> m >> _t;
  db t=_t;
  vector<vector<double>> dp(n+1,vector<double>(m+1,INF));
  dp[1][1]=0;
  auto calc=[&](db a,db b){
    if(a<b){
      return a;
    }else if(a>b+t){
      return b+t/2;
    }else{
      db x=a-b;
      assert(0<=x&&x<=t);
      return ((b+x/2)*x+a*(t-x))/t;
    }
  };
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(i>1||j>1){
        dp[i][j]=(calc(dp[i-1][j],dp[i][j-1])+calc(dp[i][j-1],dp[i-1][j]))/2;
      }
      cerr << dp[i][j] << " \n"[j==m];
    }
  }
  cout << fixed << setprecision(15);
  cout << dp[n][m];
}