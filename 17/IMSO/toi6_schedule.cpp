/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi6_schedule
 * ALGO		: Fenwick Tree
 * DATE		: 25 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Fenwick{
	int tree[500500];
	void update(int idx, int val){
		for(; idx<=500000; idx+=idx&-idx){
			tree[idx] += val;
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

bool ok[500500];

struct EVP{
	int idx, type, i;
	bool operator < (const EVP& o) const{
		if(idx != o.idx){
			return idx < o.idx;
		}
		return type < o.type;
	}
};

void solve(){
	int n, k, m, x;
	cin >> n >> k >> m;
	vector<EVP> line;
	for(int i=1, l, r; i<=n; ++i){
		cin >> l >> r;
		line.push_back({l, 1, i});
		line.push_back({r + 1, 0, i});
	}
	sort(line.begin(), line.end());
	for(auto x: line){
		if(x.type == 0){
			if(ok[x.i]){
				fw.update(x.idx, -1);
			}
		}
		else{
			if(fw.read(x.idx) < k){
				fw.update(x.idx, 1);
				ok[x.i] = true;
			}
		}
	}
	while(m--){
		cin >> x;
		cout << (ok[x] ? "Y": "N") << " " ;
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
