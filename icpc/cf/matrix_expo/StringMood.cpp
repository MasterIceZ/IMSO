#include <bits/stdc++.h>

using ll = long long;
const ll MOD = 1e9 + 7ll; 

#include "mint.hpp"
#include "matrix.hpp"

using namespace std;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	matrix_t<mint, 2> base, answer;
	answer = matrix_t<mint, 2>::identity();
	base.val[1][1] = 19; base.val[1][2] = 7;
	base.val[2][1] = 6; base.val[2][2] = 20;
	for(; n>0ll; n>>=1ll, base=base*base) {
		if(n & 1ll) {
			answer = base * answer;
		}
	}
	cout << answer.val[1][1] << "\n";
	return 0;
}
