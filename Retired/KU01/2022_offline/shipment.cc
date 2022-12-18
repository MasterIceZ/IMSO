#include <bits/stdc++.h>

using namespace std;

int n;

int count(vector<int> a, vector<int> b, int mid){
	int cnt = 0;
	for(int i=0, j=n-1; i<n && j>=0; ++i, --j){
		while(a[i] + b[j] > mid && j >= 0){
			j--;
		}
		if(j == -1){
			break;
		}
		cnt++;
	}
	return cnt;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int k;
	cin >> n >> k;
	vector<vector<int>> a(4, vector<int> (n));
	for(int s=0; s<4; ++s){
		for(int i=0; i<n; ++i){
			cin >> a[s][i];
		}
		sort(a[s].begin(), a[s].end());
	}
	int l = 1, r = 1e8;
	while(l < r){
		int mid = (l + r) >> 1;
		int cnt = count(a[0], a[2], mid) + count(a[1], a[3], mid);
		if(cnt >= k){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << l << "\n";
	return 0;
}
