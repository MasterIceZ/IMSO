#include <iostream>

using namespace std;

using ll = long long;

const int MxN = 1e6 + 10;
ll krab[MxN];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	ll mod;
	cin >> n >> mod;
	krab[0] = 1ll;
	for(ll i=3; i<=n; ++i){
		krab[i] = (krab[i - 1] * (i - 1) + ((i - 1) * (i - 2) / 2) % mod * krab[i - 3])% mod;
	}
	cout << krab[n];
	return 0;
}
