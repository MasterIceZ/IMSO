#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 150050;
const ll MOD = 998244353ll;

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

struct fenwick_tree {
	mint t[MxN];
	void update(int idx, mint v) {
		for(; idx<MxN; idx+=idx&-idx) {
			t[idx] += v;
		}
	}
	mint query(int idx) {
		mint res = 0;
		for(; idx>0; idx-=idx&-idx) {
			res += t[idx];
		}
		return res;
	}
};

mint a[MxN];
vector<int> adj[MxN];
int sz[MxN], level[MxN], parent[MxN], tin[MxN], tout[MxN], rev_timer[MxN], head[MxN], heavy[MxN], timer;
fenwick_tree fw;

auto dfs(int u, int p) -> void {
	sz[u] = 1;
	level[u] = level[p] + 1;
	parent[u] = p;
	int cur_heavy = 0, cur_max = 0;
	for(auto v: adj[u]) {
		if(v == p) {
			continue;
		}
		dfs(v, u);
		sz[u] += sz[v];
		if(cur_max < sz[v]) {
			cur_heavy = v;
			cur_max = sz[v];
		}
	}
	heavy[u] = cur_heavy;
};

auto hld(int u, int p) -> void {
	if(head[u] == 0) {
		head[u] = u;
	}
	tin[u] = ++timer;
	rev_timer[timer] = u;
	if(heavy[u] != 0) {
		head[heavy[u]] = head[u];
		hld(heavy[u], u);
	}
	for(auto v: adj[u]) {
		if(v == p || v == heavy[u]) {
			continue;
		}
		hld(v, u);
	}
	tout[u] = timer;
};

auto update(int l, int r, mint v) -> void {
	fw.update(l, v);
	fw.update(r + 1, -v);
}

auto main(int argc, char *argv[]) -> signed {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
	}
	dfs(1, 0);
	hld(1, 0);
	auto mop = [&](mint base, ll p) {
		mint res = 1;
		for(; p>0ll; p>>=1ll, base=base*base) {
			if(p & 1ll) {
				res = res * base;
			}
		}
		return res;
	};
	mint df = mop(n, MOD - 2);
	auto query = [&](int u) {
		mint res = 0ll;
		while(head[u] != 0) {
			res += a[parent[u]] * (n - sz[heavy[u]]);
			u = parent[head[u]];
		}
		return res;
	};
	while(q--) {
		int o;
		cin >> o;
		if(o == 1) {
			int v;
			mint d;
			cin >> v >> d;
			a[v] += d;
			update(1, tin[v] - 1, d * sz[v]);
			update(tout[v] + 1, MxN, d * sz[v]);
			if(heavy[v]) {
				update(tin[heavy[v]], tout[heavy[v]], d * (n - sz[heavy[v]]));
			}
		}
		else {
			int v;
			cin >> v;
			mint answer = a[v] * n + fw.query(tin[v]);
			mint to_add = query(v);
			answer = answer + to_add;
			cout << answer * df << "\n";
		}
	}
	return 0;
}
