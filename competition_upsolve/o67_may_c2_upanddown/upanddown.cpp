#include <bits/stdc++.h>
#include "upanddown.h"

using namespace std;
using ll = long long;

const int MxN = 200020;
const int MxA = 400040;
const ll MOD = 1e9 + 7ll;

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
ll Mint<0ll>::Mod=MOD;
using mint = Mint<MOD,3>;
using vm = vector<mint>;

struct fenwick_tree {
	vm t;
	int n;
	fenwick_tree(int _n) {
		n = _n;
		t.resize(n);
	}
	void update(int idx, ll v) {
		for(; idx<n; idx+=idx&-idx) {
			t[idx] += v;
		}
	}
	mint query(int idx) {
		mint res = 0ll;
		for(; idx>0; idx-=idx&-idx) {
			res += t[idx];
		}
		return res;
	}
};

fenwick_tree from_l(MxA), from_r(MxA), suf_sum(MxA);

long long upanddown(int N, std::vector<int> X) {
	for(int i=N-1; i>=0; --i) {

	}
	return 0;
}
