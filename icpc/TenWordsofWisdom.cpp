#include <bits/stdc++.h>

using namespace std;

signed main(int argc, char *argv[]){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int c=-1, d;
		for(int i=1, a, b; i<=n; ++i){
			cin >> a >> b;
			if(a <= 10 && b > c){
				c = b;
				d = i;
			}
		}
		cout <<d << "\n";
	}
}
