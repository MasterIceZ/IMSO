#include <bits/stdc++.h>
using namespace std;

const int MxN = 100010;

int a[MxN], lis[MxN];

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
	}
	int lis_size = 0;
	for(int i=0; i<n; ++i) {
		int idx = lower_bound(lis, lis + lis_size, a[i]) - lis;
		if(idx == lis_size) {
			lis_size++;
		}
		lis[idx] = a[i];
	}
	cout << "LIS = " << lis_size << "\n";
	return 0;
}
