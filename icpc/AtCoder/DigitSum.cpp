#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxD = 10010; // max digit
const int MxS = 110; // max sum
const ll MOD = 1e9 + 7ll;

ll modmul(ll a, ll b, ll mod) {
  ll res = (a * b - ll(1.l * a * b / mod) * mod) % mod;
  if (res < 0)
    res += mod;
  return res;
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

mint dp[MxD][MxS], answer = 0ll;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  string s;
  int d;
  cin >> s >> d;
  int n = s.size();
  s = " " + s;
  dp[1 + n][0] = 1ll;
  for(int digit=n; digit>=1; --digit) {
    for(int sum=0; sum<=d; ++sum) {
      for(int cur_digit=0; cur_digit<=9; ++cur_digit) {
        dp[digit][sum] += dp[digit + 1][(sum + cur_digit) % sum];
      }
    }
  }
  int tod = 0;
  for(int digit=1; digit<=n; ++digit) {
    for(int cur_digit=0; cur_digit<s[digit] - '0'; ++cur_digit) {
      answer += dp[digit + 1][(tod + cur_digit) % d];
    }
    tod = (tod + s[digit] - '0') % d;
  }
  cout << answer + (tod == 0) << "\n";
  return 0;
}