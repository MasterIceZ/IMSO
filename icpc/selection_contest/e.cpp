#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N=1e5+5;
const ll M=5e5+5;
const ll mod=998244353;

ll n;
vector<ll> a[5],cnt[5],pos[5];
vector<tuple<ll,ll,ll>> vec;
ll ans;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for(ll i=0;i<5;i++){
    a[i].assign(n+5,0);
    cnt[i].assign(5*n+5,0);
    pos[i].assign(n+5,0);
  }
  for(ll i=0;i<5;i++){
    for(ll j=1;j<=n;j++){
      cin >> a[i][j];
      vec.emplace_back(a[i][j],i,j);
    }
  }
  sort(vec.begin(),vec.end());
  for(ll i=0;i<n*5;i++){
    auto [z,x,y]=vec[i];
    pos[x][y]=i+1;
  }
  for(ll i=0;i<5;i++){
    for(ll j=1;j<=n;j++)cnt[i][pos[i][j]]++;
    for(ll j=1;j<=5*n;j++)cnt[i][j]+=cnt[i][j-1];
  }
  for(ll t=0;t<5;t++){
    if(t){
      swap(a[0],a[t]);
      swap(pos[0],pos[t]);
      swap(cnt[0],cnt[t]);
    }
    auto calc=[&](ll x,ll y,ll z,ll w){
      for(ll i=1;i<=n;i++){
        ll p=pos[0][i];
        ans+=cnt[x][p-1]*cnt[y][p-1]%mod*(n-cnt[z][p])%mod*(n-cnt[w][p])%mod*a[0][i]%mod;
        ans%=mod;
      }
    };
    calc(1,2,3,4);
    calc(1,3,2,4);
    calc(1,4,2,3);
    calc(2,3,1,4);
    calc(2,4,1,3);
    calc(3,4,1,2);
  }
  cout << ans << "\n";
}