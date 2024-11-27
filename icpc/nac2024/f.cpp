#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s[3];
  for(int i=0;i<3;i++)cin >> s[i];
  int pos[3]={};
  vector<string> ans;
  auto rot1=[&](int i,int d){
    int dif=pos[i]-d;
    dif%=10;
    if(dif<0)dif+=10;
    if(dif==0)return;
    pos[i]=d;
    string op="";
    op.push_back("ogr"[i]);
    op.push_back(char('0'+dif));
    ans.emplace_back(op);
  };
  auto rot2=[&](int x){
    x%=9;
    if(x<0)x+=9;
    if(x==0)return;
    string op="c";
    op.push_back(char('0'+x));
    ans.emplace_back(op);
  };
  auto norm=[&](int x){
    x%=10;
    if(x<0)x+=10;
    return x;
  };
  auto work=[&](int i1,int j1,int i2,int j2){
    rot1(i1,j1);
    rot1(i2,j2-3);
    rot2(i1-i2);
    rot1(i2,j2-2);
    rot2(i2-i1);
    char x=s[i1][j1],y=s[i2][j2];
    s[i1][j1]=s[i1][norm(j1+1)];
    s[i1][norm(j1+1)]=s[i1][norm(j1+2)];
    s[i1][norm(j1+2)]=y;
    s[i2][j2]=s[i2][norm(j2-1)];
    s[i2][norm(j2-1)]=s[i2][norm(j2-2)];
    s[i2][norm(j2-2)]=s[i2][norm(j2-3)];
    s[i2][norm(j2-3)]=x;
  };
  string col="ogr";
  auto check=[&](){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        if(s[0][i]!=col[0]){
          if(s[1][j]==col[0]){
            work(0,i,1,j);
            return true;
          }
          if(s[2][j]==col[0]){
            work(0,i,2,j);
            return true;
          }
        }
        if(s[1][i]!=col[1]){
          if(s[0][j]==col[1]){
            work(1,i,0,j);
            return true;
          }
          if(s[2][j]==col[1]){
            work(1,i,2,j);
            return true;
          }
        }
        if(s[2][i]!=col[2]){
          if(s[1][j]==col[2]){
            work(2,i,1,j);
            return true;
          }
          if(s[0][j]==col[2]){
            work(2,i,0,j);
            return true;
          }
        }
      }
    }
    return false;
  };
  while(check());
  cout << ans.size() << "\n";
  for(auto x:ans){
    cout << x << "\n";
  }
  return 0;
}