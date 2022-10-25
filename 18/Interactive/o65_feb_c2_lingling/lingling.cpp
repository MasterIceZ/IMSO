#include "lingling.h"
#include <vector>

using namespace std;

using ll = long long;
const int MxN = 200020;
int a[MxN];
ll sum = 0ll, tree[MxN];

void update(int idx, ll v){
	for(; idx<=200000; idx+=idx&-idx){
		tree[idx] = tree[idx] + v;
	}
}

ll query(int idx){
	ll res = 0ll;
	for(; idx; idx-=idx&-idx){
		res = res + tree[idx];
	}
	return res;
}

void init_monkeys(std::vector<int> P, int Q){
	int n = (int) P.size();
	for(int i=1; i<=n; ++i){
		a[i] = P[i - 1] + 1;
	}
	for(int i=n; i>=1; --i){
		sum = sum + query(a[i]);
		update(a[i], 1ll);
	}
}

long long minimum_branches(int L, int R){
	return sum;
}
