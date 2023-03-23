#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map<int, int> m;
	for(int i=1, x, y; i<=n; ++i){
		cin >> x >> y;
		m[x]++, m[y]--;
	}
	int s = 0, cnt = 0;
	for(auto x: m){
		s += x.second;
		if(s == 0){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
