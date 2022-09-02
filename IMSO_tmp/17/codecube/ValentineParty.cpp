/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Valentine Party
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

const int MxN = 1000100;
int n;

struct Fenwick{
	int tree[MxN];
	void update(int idx, int v){
		for(; idx<=1000000; idx+=idx&-idx){
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
	int a, k, d, q, x;
	cin >> a >> k >> d >> q;
	if(a - k < 1){
		fw.update(a + k + 1, -d);
		fw.update(n - k + a, d);
		fw.update(1, d);
	}
	else if(a + k > n){
		fw.update(a - k, d);
		fw.update(a + k - n + 1, -d);
		fw.update(1, d);
	}
	else{
		fw.update(a - k, d);
		fw.update(a + k + 1, -d);
	}
	while(q--){
		cin >> x;
		cout << max(0, 10000 - fw.read(x)) << " ";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> n >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
