#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 200200;
int n, a[200200];

void calc(int x){
	int idx, res = 0;
	for(int i=1; i<n; ++i){
		if(x - a[i] <= a[i]){
			break;
		}
		idx = upper_bound(a + 1, a + n + 1, x - a[i]) - (a + 1);
		res += idx - i - 1;
	}
	return res;
}

void solve(){
	int l, r;
	cin >> n >> l >> r;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	cout << calc(r) - calc(l - 1);
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
