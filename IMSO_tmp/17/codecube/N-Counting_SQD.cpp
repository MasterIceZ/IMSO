/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: N-Counting
 * ALGO		: Square Root Decompostion
 * DATE		: 4 Feb 2022
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
int a[MxN];
vector<int> cluster[155];

void solve(){
	int n, q;
	cin >> n >> q;
	int sq = sqrt(n);
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		cluster[i / sq].push_back(a[i]);
	}
	for(int i=0; i<=150; ++i){
		sort(cluster[i].begin(), cluster[i].end());
	}
	for(int i=1; i<=q; ++i){
		int st, ed, s, e, res = 0;
		cin >> st >> ed >> s >> e;
		for(int x=st; x<=ed; ){
			if(x % sq == 0 && x + sq - 1 <= ed){
				res += (upper_bound(cluster[x / sq].begin(), cluster[x / sq].end(), e) - lower_bound(cluster[x / sq].begin(), cluster[x / sq].end(), s));
				x += sq;
			}
			else{
				res += (s <= a[x] && a[x] <= e);
				x += 1;
			}
		}
		cout << res << " " ;
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
