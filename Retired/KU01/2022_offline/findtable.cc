#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> a(n + 1, vector<int> (n + 1));
	vector<int> r(n + 1), c(n + 1);
	for(int i=1; i<=n; ++i){
		cin >> r[i];
	}
	for(int i=1; i<=n; ++i){
		cin >> c[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			int mn = min(r[i], c[j]);
			r[i] -= mn;
			c[j] -= mn;
			a[i][j] = mn;
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
