/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct20_landval
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

const int MxN = 200200;

int n;

struct Fenwick{
	int tree[MxN];
	void update(int idx, int v){
		for(; idx<=n; idx+=idx&-idx){
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

void solve(){
	int m, a, b, c, d;
	cin >> n >> m;
	while(m--){
		cin >> a;
		if(a == 1){
			cin >> b >> c >> d;
			fw.update(b, d);
			fw.update(c+1, -d);
		}
		else{
			cin >> b;
			cout << fw.read(b) << "\n";
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
