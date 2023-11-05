#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=105;
const int mod=1e9+7;
const ld pi=acos(-1.l);

int n;
ld r;
ld x[N],y[N],z[N];

ld dist(int i,int j){
  ld dx=x[i]-x[j];
  ld dy=y[i]-y[j];
  ld dz=z[i]-z[j];
  return sqrtl(dx*dx+dy*dy+dz*dz);
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> r;
  for(int i=0;i<n;i++)cin >> x[i] >> y[i] >> z[i];
  ld ans=n*4.0/3.0*pi*r*r*r;
  for(int i=0;i<n;i++){
    ld d=dist(i,(i+1)%n)/2.0;
    ans-=2.0/3.0*pi*(r-d)*(r-d)*(2*r+d);
  }
  cout << fixed << setprecision(20) << ans << "\n";
}