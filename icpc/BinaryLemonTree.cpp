#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 909091ll;

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
ll Mint<0ll>::Mod=ll(MOD);
using mint = Mint<MOD,3>;
using vm = vector<mint>;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vm v(2 * n + 1);
	v[0] = 1;
	for(int i=1; i<=2*n; ++i) {
		v[i] = v[i - 1] * (ll) i;
	}
	cout << v[2 * n] / v[n] / v[n] / ((mint) (1ll + n)) << "\n";
	
	return 0;
}
