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

using matrix_t = vector<vector<mint>>;

matrix_t mul(matrix_t a, matrix_t b) {
	assert(a[0].size() == b.size());
	matrix_t res(a.size(), vector<mint> (b[0].size()));
	for(int i=1; i<(int) a.size(); ++i) {
		for(int j=1; j<(int) b.size(); ++j) {
			for(int k=1; k<(int) b[0].size(); ++k) {
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return res;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	vector<matrix_t> base(30);
	base[0].resize(n + 1, vector<mint> (n + 1));
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v;
		base[0][u][v] = 1;
	}
	for(int i=1; i<30; ++i) {
		base[i] = mul(base[i - 1], base[i - 1]);
	}
	while(q--) {
		int u, v, k;
		cin >> u >> v >> k;
		matrix_t answer(2, vector<mint> (n + 1));
		answer[1][u] = 1;
		for(int state=0; state<30; ++state) {
			if(!(k & (1 << state))) {
				continue;
			}
			answer = mul(answer, base[state]);
		}
		cout << answer[1][v] << "\n";
	}
	return 0;
}
