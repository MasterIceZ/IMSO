/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o61_mar_c2_fixing
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

void solve(){
	int n, m, k, x;
	cin >> n >> m >> k;
	vector<int> v;
	int last = 0, cnt = 0;
	for(int i=1; i<=m; ++i){
		cin >> x;
		if(i != 1 && last + 1 != x){
			v.push_back(x - last - 1);
			cnt += v.back();
		}
		last = x;
	}
	sort(v.begin(), v.end(), greater<int>());
	for(int i=0; i<k-1 && i<v.size(); ++i){
		cnt -= v[i];
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
