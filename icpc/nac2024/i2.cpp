#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 42;
const int M = 1002;
const int K = 2502;

bitset<K> dp[N][N][M];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int m=n*(n-1)/2;
  string s;
  cin >> s;
  dp[0][0][0][0]=1;
  for(int i=0;i<n;i++){
    if(s[i]=='N'||s[i]=='?'){
      for(int j=0;j+1<=n;j++){
        for(int k=0;k<=m;k++){
          dp[i+1][j+1][k]|=dp[i][j][k];
        }
      }
    }
    if(s[i]=='A'||s[i]=='?'){
      for(int j=0;j<=n;j++){
        for(int k=0;k+j<=m;k++){
          dp[i+1][j][k+j]|=dp[i][j][k];
        }
      }
    }
    if(s[i]=='C'||s[i]=='?'){
      for(int j=0;j<=n;j++){
        for(int k=0;k<=m;k++){
          dp[i+1][j][k]|=dp[i][j][k]<<k;
        }
      }
    }
    if(s[i]!='N'&&s[i]!='A'&&s[i]!='C'){
      for(int j=0;j<=n;j++){
        for(int k=0;k<=m;k++){
          dp[i+1][j][k]|=dp[i][j][k];
        }
      }
    }
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(dp[n][i][j][k]){
        auto ans=s;
        int x=i,y=j,z=k;
        for(int i=n-1;i>=0;i--){
          assert(dp[i+1][x][y][z]);
          if(s[i]!='?'){
            if(s[i]=='N'){
              x--;
            }else if(s[i]=='A'){
              y-=x;
            }else if(s[i]=='C'){
              z-=y;
            }
            continue;
          }
          if(x-1>=0&&dp[i][x-1][y][z]){
            x--;
            ans[i]='N';
          }else if(y-x>=0&&dp[i][x][y-x][z]){
            y-=x;
            ans[i]='A';
          }else if(z-y>=0&&dp[i][x][y][z-y]){
            z-=y;
            ans[i]='C';
          }else{
            ans[i]='X';
          }
        }
        cout << ans;
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}