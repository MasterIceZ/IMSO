#include<bits/stdc++.h>

using namespace std;

const int INF= INT_MAX/2;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i];
  }
  int tot=accumulate(a.begin(),a.end(),0);
  vector<int> dp(tot+1);
  for(int i=0;i<n;i++){
    vector<int> ndp(tot+1);
    for(int j=0;j<=tot;j++){
      ndp[j]=dp[j]+b[i];
      if(j>=a[i]){
        ndp[j]=min(ndp[j],dp[j-a[i]]);
      }
    }
    swap(dp,ndp);
  }
  int ans=tot;
  for(int i=0;i<=tot;i++){
    ans=min(ans,max(i,dp[i]));
  }
  cout << ans;
}