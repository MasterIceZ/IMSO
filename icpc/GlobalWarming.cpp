#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;
int lis[MxN], lds[MxN], lds_size[MxN], lis_size[MxN], a[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int n, x;
	cin >> n >> x;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int sz = 0;
	for(int i=n; i>=1; --i){
		int idx = lower_bound(lds, lds + sz, -a[i]) - lds;
		if(idx == sz){
			sz++;
		}
		lds[idx] = -a[i];
		lds_size[i] = idx + 1;
	}
	sz = 0;
	int res = 0;
	for(int i=1; i<=n; ++i){
		int idx = lower_bound(lis, lis + sz, a[i] + x) - lis;
		res = max(res, lds_size[i] + idx);
		idx = lower_bound(lis, lis + sz, a[i]) - lis;
		if(idx == sz){
			sz++;
		}
		lis[idx] = a[i];
		lis_size[i] = sz;
	}
	cout << max(res, lis_size[n]) << "\n";
	return 0;
}
