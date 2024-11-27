#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7ll;
const int MxN = 100010;

template<ll M,ll root=0>
struct Mint{
    ll x;
    constexpr Mint():x(0){}
    constexpr Mint(ll x):x(norm(x%get_mod())){}
    static ll Mod;
    static constexpr ll get_mod(){return M>0?M:Mod;}
    static constexpr void set_mod(ll Mod_){Mod=Mod_;}
    static constexpr Mint get_root(){return Mint(root);}
    constexpr ll norm(ll x)const{if(x<0)x+=get_mod();if(x>=get_mod())x-=get_mod();return x;}
    explicit constexpr operator ll()const{return x;}
    constexpr Mint operator-()const{return Mint()-Mint(*this);};
    constexpr Mint operator+()const{return Mint(*this);};
    constexpr Mint inv()const{
        ll a=x,b=get_mod(),u=1,v=0,q;
        while(b>0){
            q=a/b;
            a-=q*b;
            u-=q*v;
            swap(a,b);
            swap(u,v);
        }
        return Mint(u);
    }
    constexpr ll mul(ll a,ll b)const{
        ll mod=get_mod();
        ll res=(a*b-ll(1.l*a*b/mod)*mod)%mod;
        if(res<0)res+=mod;
        return res;
    }
    constexpr Mint &operator+=(const Mint &rhs){x=norm(x+rhs.x);return *this;}
    constexpr Mint &operator-=(const Mint &rhs){x=norm(x-rhs.x);return *this;}
    constexpr Mint &operator*=(const Mint &rhs){x=mul(x,rhs.x);return *this;}
    constexpr Mint &operator/=(const Mint &rhs){x=mul(x,rhs.inv().x);return *this;}
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
template<>
ll Mint<0ll>::Mod=ll(1e18)+9;
using mint = Mint<MOD,3>;

struct node_t;
using pnode_t = node_t *;

struct node_t {
  mint val;
  pnode_t l, r;
  node_t(mint _val=0ll):
    val(_val), l(nullptr), r(nullptr) {}
};

struct state_t {
  int v;
  pnode_t p;
  bool operator < (const state_t &o) const {
    
  }
  state_t(int _v, pnode_t _p):
    v(_v), p(_p) {}
};

vector<pair<int, ll>> adj[MxN];
ll w;
pnode_t roots[MxN];
mint pw[MxN];

namespace persist {
  mint merge_val(mint a, mint b) {
    return 1ll;
  }
  void build(int l, int r, pnode_t &cur) {
    cur = new node_t();
    cur->val = pw[r] - pw[l - 1];
    if(l == r) {
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, cur->l);
    build(mid + 1, 1, cur->r);
  }
  void update(int l, int r, int id, pnode_t &cur, pnode_t pre) {
    cur = new node_t(*pre);
    cur->val = cur->val + pw[id];
    if(l == r) {
      return ;
    }
    int mid = (l + r) >> 1;
    if(id <= mid) {
      update(l, mid, id, cur->l, pre->l);
    }
    else {
      update(mid + 1, r, id, cur->r, pre->r);
    }
  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, s, t;
  cin >> n >> m;
  for(int i=1, u, v; i<=n; ++i) {
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  cin >> s >> t;
  pw[0] = 1ll;
  for(int i=1; i<=n; ++i) {
    pw[i] = pw[i - 1] * 2ll;
  }
  persist::build(1, n, roots[0]);
  return 0;
}