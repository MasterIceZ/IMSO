#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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
ll Mint<0ll>::Mod=ll(1e18)+9;
using mint = Mint<MOD,3>;

template<typename T, size_t S>
struct matrix_t:array<array<T, S + 1>, S + 1> {
	matrix_t() {
		for(int i=1; i<=(int) S; ++i) {
			for(int j=1; j<=(int) S; ++j) {
				(*this)[i][j] = 0;
			}
		}
	}
	static constexpr matrix_t set_max() {
		matrix_t res;
		for(int i=1; i<=(int) S; ++i) {
			for(int j=1; j<=(int) S; ++j) {
				res[i][j] = 3e18 + 100ll;
			}
		}
		return res;
	}
	static constexpr matrix_t identity() {
		matrix_t res;
		for(int i=1; i<=(int) S; ++i) {
			res[i][i] = 1;
		}
		return res;
	}
	matrix_t operator * (const matrix_t &o) {
		matrix_t res = set_max();
		for(int i=1; i<=(int) S; ++i) {
			for(int j=1; j<=(int) S; ++j) {
				for(int k=1; k<=(int) S; ++k) {
					res[i][j] = min(res[i][j], (*this)[i][k] + o[k][j]);
				}
			}
		}
		return res;
	}
};

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	ll k;
	cin >> n >> m >> k;
	matrix_t<ll, 100> base = matrix_t<ll, 100>::set_max();
	matrix_t<ll, 100> answer = matrix_t<ll, 100>::identity();
	for(int i=1, u, v, w; i<=m; ++i) {
		cin >> u >> v >> w;
		base[u][v] = min(base[u][v], (ll) w);
	}
	for(; k>0ll; k>>=1ll, base=base*base) {
		if(k & 1) {
			answer = base * answer;
		}
	}
	ll res = 3e18 + 100ll;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			res = min(res, answer[i][j]);
		}
	}
	cout << (res >= 1e18L + 30ll ? "IMPOSSIBLE": to_string(res)) << "\n";
	return 0;
}

