#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7ll;

ll modmul(ll a, ll b, ll mod) {
  ll res = (a * b - ll(1.l * a * b / mod) * mod) % mod;
  if (res < 0)
    res += mod;
  return res;
}

ll modinv(ll a,ll b) {
    ll x=0,x1=1;
    while(a!=0){
        ll q=b/a;
        b-=q*a;
        x-=q*x1;
        swap(a,b);
        swap(x,x1);
    }
    return x;
}

template<ll M>
struct Mint{
    ll x;
    constexpr Mint():x(0){}
    constexpr Mint(ll x):x(norm(x%getMod())){}
    static ll Mod;
    constexpr static ll getMod(){return M>0?M:Mod;}
    constexpr static void setMod(ll Mod_){Mod=Mod_;}
    constexpr ll norm(ll x)const{if(x<0)x+=getMod();if(x>=getMod())x-=getMod();return x;}
    explicit constexpr operator ll()const{return x;}
    constexpr Mint operator-()const{Mint res;res.x=norm(-x);return res;}
    constexpr Mint inv()const{return modinv(x,getMod());}
    constexpr Mint &operator+=(const Mint &rhs){x=norm(x+rhs.x);return *this;}
    constexpr Mint &operator-=(const Mint &rhs){x=norm(x-rhs.x);return *this;}
    constexpr Mint &operator*=(const Mint &rhs){x=modmul(x,rhs.x,getMod());return *this;}
    constexpr Mint &operator/=(const Mint &rhs){x=modmul(x,rhs.inv().x,getMod());return *this;}
    constexpr Mint &operator++(){return *this+=1;}
    constexpr Mint &operator--(){return *this-=1;}
    constexpr Mint operator++(int){Mint res=*this;*this+=1;return res;}
    constexpr Mint operator--(int){Mint res=*this;*this-=1;return res;}
    friend constexpr Mint operator+(Mint lhs,const Mint &rhs){return lhs+=rhs;}
    friend constexpr Mint operator-(Mint lhs,const Mint &rhs){return lhs-=rhs;}
    friend constexpr Mint operator*(Mint lhs,const Mint &rhs){return lhs*=rhs;}
    friend constexpr Mint operator/(Mint lhs,const Mint &rhs){return lhs/=rhs;}
    friend istream &operator>>(istream &is,Mint &o){ll x{};is>>x;o=Mint(x);return is;}
    friend ostream &operator<<(ostream &os,const Mint &o){return os<<o.x;}
    friend constexpr bool operator==(const Mint &lhs,const Mint &rhs){return lhs.x==rhs.x;}
    friend constexpr bool operator!=(const Mint &lhs,const Mint &rhs){return lhs.x!=rhs.x;}
    friend constexpr bool operator<(const Mint &lhs,const Mint &rhs){return lhs.x<rhs.x;} // for std::map
};
using mint = Mint<MOD>;

const int MxN = 21;

bool a[MxN][MxN];
mint dp[1 << MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=0; i<=n-1; ++i) {
    for(int j=0; j<=n-1; ++j) {
      cin >> a[i][j];
    }
  }
  int max_mask = (1 << n) - 1;
  dp[0] = 1ll;
  for(int mask=0; mask<=max_mask; ++mask) {
    int cnt = __builtin_popcount(mask);
    for(int i=0; i<n; ++i) {
      if((mask & (1 << i)) || !a[cnt][i]) {
        continue;
      }
      int next_mask = (mask | (1 << i));
      dp[next_mask] += dp[mask];
    }
  }
  cout << dp[max_mask] << "\n";
  return 0;
}