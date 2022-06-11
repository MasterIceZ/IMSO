/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Triangle Knives
 * ALGO		: Fenwick Tree
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1000100;

struct Fenwick{
	ll tree[1000100];
	ll sum = 0, count = 0;
	void update(int idx, ll v){
		idx += 1;
		for(; idx<=1000020; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	ll read(int idx){
		idx += 1;
		ll res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} up, down;

ll b[MxN], f[MxN];

void solve(){
	ll n, l, q, a, x;
	cin >> n >> l >> q;
	up.update(l, n);
	up.count = n;
	up.sum = l * n;
	for(int i=1; i<=n; ++i){
		b[i] = l;
	}
	while(q--){
		char o;
		cin >> o;
		if(o == 's'){
			cin >> a >> x;
			a += 1;
			if(!f[a]){
				up.update(b[a], -1);
				up.sum -= b[a];
			}
			else{
				down.update(b[a], -1);
				down.sum -= b[a];
			}
			b[a] += x;
			if(b[a] > l || (b[a] == l && f[a])){
				b[a] %= l;
			}
			if(!f[a]){
				up.update(b[a], 1);
				up.sum += b[a];
			}
			else{
				down.update(b[a], 1);
				down.sum += b[a];
			}
			dbg(up.sum, down.sum, up.count, down.count);
		}
		else if(o == 'f'){
			cin >> a;
			a += 1;
			if(!f[a]){
				up.sum -= b[a];
				up.update(b[a], -1);
				if(b[a] == l){
					b[a] = 0;
				}
				down.sum += b[a];
				down.update(b[a], 1);
				up.count -= 1;
				down.count += 1;
			}
			else{
				down.sum -= b[a];
				down.update(b[a], -1);
				if(b[a] == 0){
					b[a] = l;
				}
				up.sum += b[a];
				up.update(b[a], 1);
				down.count -= 1;
				up.count += 1;
			}
			f[a] ^= 1;
			dbg(up.sum, down.sum, up.count, down.count);
		}
		else{
			cin >> a;
			ll tmp = a * up.count - up.sum + l * (up.count - up.read(a - 1));
			ll tmp2 = down.sum - a * down.count + l * down.read(a);
			dbg(tmp2, tmp);
			tmp += tmp2;
			cout << tmp << "\n";
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
