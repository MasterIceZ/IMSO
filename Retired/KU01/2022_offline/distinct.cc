#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	set<int> st;
	vector<int> a(n + 1);
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		int sum = 0;
		for(int j=i; j<=n; ++j){
			sum += a[j];
			st.emplace(sum);
		}
	}
	cout << st.size();
}
