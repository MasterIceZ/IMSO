/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: N-Counting
 * ALGO		: 
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

const int MxN = 20020;
struct FenwickTree{
	int tree[440440];
	void update(int idx, int v){
		for(; idx<=440339; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	int read(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} fw;

struct Query{
	int type, minn, maxx, idx;
	Query(int a, int b, int c, int d): type(a), minn(b), maxx(c), idx(d) {}
};

int a[20020];
vector<Query> qr[20020];
int res[200200];

void solve(){
	int n, q;
	cin >> n >> q;
	vector<int> c;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		c.push_back(a[i]);
	}
	for(int i=1; i<=q; ++i){
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		qr[a - 1].emplace_back(-1, x, y, i);
		qr[b].emplace_back(1, x, y, i);
		c.push_back(x);
		c.push_back(y);
	}
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	for(int i=1; i<=n; ++i){
		int cur = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
		fw.update(cur, 1);
		for(auto x: qr[i]){
			int minn = upper_bound(c.begin(), c.end(), x.minn) - c.begin();
			int maxx = upper_bound(c.begin(), c.end(), x.maxx) - c.begin();
			res[x.idx] += x.type * (fw.read(maxx) - fw.read(minn - 1));
		}
	}
	for(int i=1; i<=q; ++i){
		cout << res[i] << " ";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
