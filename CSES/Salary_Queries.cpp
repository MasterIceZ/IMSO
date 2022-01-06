/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Salary Queries
 * ALGO		: 
 * DATE		: 6 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1000500;

struct QUERY{
	int a, b, type;
};

struct BIT{
	ll tree[MxN];
	void update(int idx, int v){
		for(; idx<=500000; idx+=idx&-idx){
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

int v[MxN];
vector<QUERY> offline;
vector<int> compress;
char c;

int to_idx(int v){
	return upper_bound(compress.begin(), compress.end(), v) - compress.begin();
}

void solve(){
	int x, y, n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> v[i];
		compress.push_back(v[i]);
	}

	while(q--){
		cin >> c >> x >> y;
		compress.push_back(x);
		compress.push_back(y);
		if(c == '!'){
			offline.push_back({x, y, 1});
		}
		else{
			offline.push_back({x, y, 2});
		}
	}

	sort(compress.begin(), compress.end());
	compress.resize(unique(compress.begin(), compress.end()) - compress.begin());

	for(int i=1, idx; i<=n; ++i){
		idx = to_idx(v[i]);
		fw.update(idx, 1);
		dbg(fw.read(idx), idx, v[i]);
	}
	for(auto x: offline){
		if(x.type == 1){
			fw.update(to_idx(v[x.a]), -1);
			v[x.a] = x.b;
			fw.update(to_idx(v[x.a]), 1);
		}
		else{
			ll amtR = fw.read(to_idx(x.b));
			ll amtL = fw.read(to_idx(x.a - 1));
			dbg(amtR, amtL);
			cout << amtR - amtL << "\n";
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
		cout << "\n";
	}
	return 0;
}
