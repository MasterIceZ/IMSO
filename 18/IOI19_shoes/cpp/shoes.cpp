#include "shoes.h"
#include <vector>

using namespace std;
using ll = long long

const int MxN = 100010;
int a[MxN << 1];
map<int, vector<int>> position;
map<int, int> mem;

struct fenwick_tree{
	ll tree[MxN << 1];
	void build(){
		for(int idx=2; idx<=200000; ++idx){
			tree[idx] = tree[idx] + 1ll;
			int nxt = idx + (idx & -idx);
			if(nxt <= 200000){
				tree[nxt] = tree[nxt] + tree[idx];
			}
		}
	}
	ll read(int idx){
		ll res = 0ll;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
	void update(int idx, ll v){
		for(; idx<=200000; idx+=idx&-idx){
			tree[idx] = tree[idx] + v;
		}
	}
} fw;

long long count_swaps(std::vector<int> s) {
	int n = s.size() / 2;
	fw.build();
	for(int i=1; i<=2 * n; ++i){
		a[i] = s[i - 1];
		position[a[i]].emplace_back(i);
	}
	ll answer = 0ll;
	for(int i=1; i<=2 * n; ++i){
		if(ok[i]){
			continue;
		}
		answer = answer + fw.read(i) + fw.read(position[-a[i]][mem]);
	}
}
