/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct15_inversion
 * ALGO		: Fenwick Tree
 * DATE		: 7 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;

struct Fenwick{
	ll tree[MxN];
	void update(int idx, int v){
		for(; idx<=100000; idx+=idx&-idx){
			tree[idx] += v;
		}
	}
	ll read(int idx){
		ll res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} fw;

int a[MxN];
vector<int> compress;

void solve(){
	int n;
	ll cnt = 0;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		compress.push_back(a[i]);
	}
	sort(compress.begin(), compress.end());
	compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
	for(int i=n; i>=1; --i){
		int idx = upper_bound(compress.begin(), compress.end(), a[i]) - compress.begin();
		cnt += fw.read(idx - 1);
		fw.update(idx, 1);
	}
	cout << cnt;
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
