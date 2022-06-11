#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int a[22];

void solve(){
	int n, l, r;
	cin >> n >> l >> r;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		for(int j=i+1; j<=n; ++j){
			if(a[i] + a[j] >= l && a[i] + a[j] <= r){
				cnt++;
			}
		}
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
