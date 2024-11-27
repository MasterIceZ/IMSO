#include<bits/stdc++.h>
using namespace std;

using db=double;
using ll=long long;
vector<tuple<ll,ll,ll>> v;
vector<tuple<db,ll,ll,ll>> v2;
vector<db> p;
ll f[6005];

bool cal (db pos){
  vector<tuple<db, ll>> vy;
  for (auto [nsin, ny, ns, nx] : v2)
  {
    vy.emplace_back(ny / (nx - pos), ns);
  }
  ll tmp = 0;
  for (auto [ny, ns] : vy)
  {
    tmp += ns;
    if (tmp == 0)
    {
      return 0;
    }
  }
  return 1;
}

int main (){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,w;
  cin >> n >> w;
  for (int i=0;i<n;i++){
    int x,y1,y2;
    cin >> x >> y1 >> y2;
    v.emplace_back(y2,y1,x);
    v2.emplace_back(y1/sqrt(x*x+y1*y1),y1,-1,x);
    v2.emplace_back(y2 / sqrt(x * x + y2 * y2),y2, 1, x);
  }
  // sort(v.begin(),v.end());
  sort(v2.begin(),v2.end());
  for (int i=0;i<n;i++){
    auto [yh1,yl1,x1]=v[i];
    for (int j=0;j<n;j++){
      auto [yh2,yl2,x2]=v[j];
      if (x1==x2) continue;
      db m=(yh1-yh2)/(x1-x2);
      if (yh1!=yh2) p.emplace_back(x1-yh1/m);

      db m = (yh1 - yl2) / (x1 - x2);
      if (yh1 != yl2) p.emplace_back(x1 - yh1 / m);

      db m = (yl1 - yh2) / (x1 - x2);
      if (yl1 != yh2)
        p.emplace_back(x1 - yl1 / m);

      db m = (yl1 - yl2) / (x1 - x2);
      if (yl1 != yl2)
        p.emplace_back(x1 - yl1 / m);
    }
  }
  p.emplace_back(0);
  sort(p.begin(),p.end());
  if (cal(p[0]-1)){
    cout << -1;
    exit(0);
  }
  for (int i=1;i<p.size();i++){
    if (p[i]>0) break;
    db mid=(p[i-1]+p[i])/2;
    mid=min(mid,0.0);
    if (cal(mid)){

    }

  }
}