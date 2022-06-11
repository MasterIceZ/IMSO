/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct20_moblies
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

const int MxN = 2020;

int n;
struct Fenwick{
	int tree[MxN][MxN];
	void update(int idxi, int idxj, int v){
		for(; idxi<=n; idxi+=idxi&-idxi){
			for(int now=idxj; now<=n; now+=now&-now){
				tree[idxi][now] += v;
			}
		}
	}
	int read(int idxi, int idxj){
		int res = 0;
		for(; idxi; idxi-=idxi&-idxi){
			for(int now=idxj; now; now-=now&-now){
				res += tree[idxi][now];
			}
		}
		return res;
	}
} fw;

void solve(){
	int opr;
	cin >> opr;
	if(opr == 0){
		cin >> n;
	}
	else if(opr == 1){
		int x, y, a;
		cin >> x >> y >> a;
		x++, y++;
		fw.update(x, y, a);
	}
	else if(opr == 2){
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		a++, b++, x++, y++;
		cout << fw.read(x, y) + fw.read(a-1, b-1) - fw.read(a-1, y) - fw.read(x, b-1) << "\n" << flush;
	}
	else{
		exit(0);
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q){
		solve();
	}
	return 0;
}
