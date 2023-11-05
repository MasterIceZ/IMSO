#include<bits/stdc++.h>

using namespace std;

typedef __int128_t ll;
typedef pair<ll,ll> p2;

const int N=1e6+5;
const int mod=1e9+7;
const ll inf=ll(1e18)*ll(1e18);

ll pw[40];

string sll(ll x){
  string s="";
  while(x>0){
    s.push_back(x%10+'0');
    x/=10;
  }
  reverse(s.begin(),s.end());
  return s;
}

void solve(){
  string s;
  int k;
  cin >> s >> k;
  int n=s.size();
  reverse(s.begin(),s.end());
  s=" "+s;
  while(s.size()<40)s.push_back('0');
  if(k==0){
    for(int i=1;i<=39;i++)if(s[i]!='9')return void(cout << sll(pw[i]) << "\n");
  }
  vector<vector<p2>> dp(40,vector<p2>(k+2,p2(inf,inf)));
  dp[0][0].first=0;
  for(int i=1;i<=39;i++){
    int num=s[i]-'0';
    for(int j=0;j<=k;j++){
      dp[i][j].first=min(dp[i][j].first,dp[i-1][j].first);
      if(num<9)dp[i][j].first=min(dp[i][j].first,dp[i-1][j].second);
      if(num>0)dp[i][j+1].second=min(dp[i][j+1].second,dp[i-1][j].first+(10-num)*pw[i]);
      dp[i][j+1].second=min(dp[i][j+1].second,dp[i-1][j].second+(9-num)*pw[i]);
    }
  }
  ll ans=dp[39][k].first;
  cout << sll(ans) << "\n";
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  pw[1]=1;
  for(int i=2;i<=39;i++)pw[i]=pw[i-1]*10;
  int t;
  cin >> t;
  while(t--)solve();
}