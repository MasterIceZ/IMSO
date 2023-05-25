#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 500050;

struct fenwick_tree{
	ll tree[MxN << 1];
	inline void update(int idx, ll v){
		for(; idx<MxN; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	inline ll query(int idx){
		ll res = 0ll;
		for(; idx>0; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} low, up;

ll n, a[MxN], b[MxN], cnt[MxN << 1];
vector<ll> c;

int main(){
	scanf("%lld", &n);
	for(int i=1; i<=n; ++i){
		scanf("%lld", &a[i]);
		c.emplace_back(a[i]);
	}
	for(int i=1; i<=n; ++i){
		scanf("%lld", &b[i]);
		c.emplace_back(b[i]);
	}
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	for(int i=1; i<=n; ++i){
		ll idx = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
		cnt[idx]++;
	}
	for(int i=1; i<=n; ++i){
		// process a[i]
	}
	return 0;
}
