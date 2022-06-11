/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
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

const int MxN = 100100;
int a[MxN];

void solve(){
	int n, w;
	cin >> n >> w;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		a[i] = abs(w - x);
	}
	vector<int> lis;
	for(int i=1; i<=n; ++i){
		int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
		if(idx == lis.size()){
			lis.push_back(a[i]);
		}
		else{
			lis[idx] = a[i];
		}
	}
//	cout << lis.size() << " " << n - lis.size() << "\n";
	cout << n - lis.size();
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
