#include <bits/stdc++.h>
using namespace std ;

using ll = long long;

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ll g = 0, x;
	for(int i=1; i<=n; ++i){
		cin >> x;
		g = __gcd(g, x);
	}
	cout << g;
	return 0;
}
