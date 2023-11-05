#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e6+5;
const int mod=1e9+7;

int n;
int a[N];
ll dp[N][5];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  for(int i=1;i<=n;i++){
    if(a[i]==1){
      dp[i][1]=(dp[i-1][1]+1)%mod;
      dp[i][2]=dp[i-1][2];
      dp[i][3]=dp[i-1][3];
    }else if(a[i]==2){
      dp[i][1]=dp[i-1][1];
      dp[i][2]=(dp[i-1][1]+2*dp[i-1][2])%mod;
      dp[i][3]=dp[i-1][3];
    }else{
      dp[i][1]=dp[i-1][1];
      dp[i][2]=dp[i-1][2];
      dp[i][3]=(dp[i-1][3]+dp[i-1][2])%mod;
    }
  }
  cout << dp[n][3];
}