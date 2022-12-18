#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> p(n + 1), v(n + 1);
	for(int i=1; i<=n; ++i){
		cin >> p[i] >> v[i];
	}
	set<int> sv;
	int cnt = n;
	for(int i=n; i>=1; --i){
		if(sv.upper_bound(v[i]) == sv.end()){
			cnt--;
		}
		sv.emplace(v[i]);
	}
	cout << cnt;
	return 0;
}
