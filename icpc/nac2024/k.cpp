#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;

const db INF = numeric_limits<db>::max();

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,w;
  cin >> n >> w;
  vector<db> a(n),b(n),c(n);
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i] >> c[i];
  }
  double mn=INF;
  vector<pair<double,double>> ranges;
  for(int i=0;i<n;i++){
    if(c[i]>=0){
      continue;
    }
    db l=INF,r=-INF;
    bool found=false;
    for(int j=0;j<n;j++){
      if(i==j||b[i]>=0){
        continue;
      }
      found=true;
      ll num=a[j]*c[i]-a[i]*b[j];
      ll den=b[j]-c[i];
      if(den==0){
        if(num<0){
          continue;
        }else{
          
        }
      }
    }
    if(!found)
    mn=min(mn,mx);
  }
  for(int i=0;i<n;i++){
    if(b[i]<=0){
      continue;
    }
    db mx=-INF;
    for(int j=0;j<n;j++){
      if(i==j||c[i]<=0){
        continue;
      }
      mx=max(mx,((a[i]*c[j])-(a[j]*b[i]))/(c[j]-b[i]));
    }
    mn=min(mn,mx);
  }
  cout << fixed << setprecision(15);
  if(mn<0){
    cout << -1 << "\n";
  }else{
    cout << mn << "\n";
  }
}