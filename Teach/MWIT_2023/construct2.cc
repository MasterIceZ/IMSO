#include <bits/stdc++.h>
using namespace std;

const int MxN = 300030;
string s;
int cnt[4], a[MxN];
map<pair<int, int>, int> mp;

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q, x;
	cin >> n >> q >> s;
	s = " " + s;
	for(int i=1; i<=n; ++i){
		cnt[s[i] == 'C']++;
		int gcd = __gcd(cnt[0], cnt[1]);
		int rate_c = cnt[0] / gcd;
		int rate_d = cnt[1] / gcd;
		mp[{rate_c, rate_d}]++;
		a[i] = mp[{rate_c, rate_d}];
	}
	while(q--){
		cin >> x;
		cout << a[x] << "\n";
	}
	return 0;
}
