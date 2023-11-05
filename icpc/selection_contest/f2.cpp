#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=105;

int n,m;
string s[N];
bool vis[N][N];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  n=n*2-1,m=m*2-1;
  s[0]=string(m+5,'.');
  s[n+1]=string(m+5,'.');
  for(int i=1;i<=n;i++){
    cin >> s[i];
    s[i]="."+s[i]+'.';
  }
  for(int t=1;t<=max(n,m);t++){
    vector<pair<int,int>> vec;
    for(int i=1;i<=n;i+=2){
      for(int j=t*2-1;j<=m-t*2+1;j+=2){
        if(min({i,n-i+1,j,m-j+1})==t*2-1)vec.emplace_back(i,j);
      }
    }
    for(auto [i,j]:vec){
      int val=s[i][j]-'0';
      for(int di=-1;di<=1;di++){
        for(int dj=-1;dj<=1;dj++){
          val-=(s[i+di][j+dj]=='#');
        }
      }

    }
  }
}