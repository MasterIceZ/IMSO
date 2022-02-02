/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct21_inc2
 * ALGO		: Dynamic Programming
 * DATE		: 1 Feb 2022
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
	int n;
	cin >> n;
	vector<int> lis;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		int idx = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
		if(idx == lis.size()){
			lis.push_back(x);
		}
		else{
			lis[idx] = x;
		}
	}
	cout << lis.size();
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
