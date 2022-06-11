/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct20_gemplant
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

struct Fenwick{
	int tree[MxN];
	void update(int idx, int v){
		for(; idx<=200000; idx+=idx&-idx){
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
	int n, m;
	cin >> n >> m;
	while(m--){
		int a, x, y;
		cin >> a >> x >> y;
		if(a == 1){
			fw.update(y, x);
		}
		else{
			cout << fw.read(y) - fw.read(x-1) << "\n";
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
