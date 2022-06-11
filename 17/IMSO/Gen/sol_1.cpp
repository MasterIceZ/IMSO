#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int a[200200], n;

int calc(int x){
	int res = 0;
	for(int i=1, j=n; i<=n && j>=i; ++i){
		while(j > i && a[j] + a[i] > x){
			j--;
		}
		if(j - i > 0){
			res += (j - i);
		}
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
	int ans = calc(r) - calc(l - 1);
	cout << ans;
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
