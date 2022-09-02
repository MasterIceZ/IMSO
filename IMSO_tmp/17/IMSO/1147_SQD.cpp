/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Segment Tree
 * ALGO		: Square Root Decomposition
 * DATE		: 20 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct SQD{
	int cluster[550], a[300300];
	int sq;
	void update(int v, int idx){
		a[idx] = v;
		for(int i=(idx/sq)*sq; i<=min(n, (idx/sq)*sq+sq); ++i){
			cluster[idx / sq] = max(cluster[x / sq], a[i]);
		}
	}
	int read(int l, int r){
		
	}
} dp;

void solve(){
	int n, q;
	cin >> n >> q;
	dp.sq = sqrt(n);
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
