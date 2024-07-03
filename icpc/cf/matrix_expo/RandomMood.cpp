#include <bits/stdc++.h>
#include "matrix.hpp"

using namespace std;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	double p;
	cin >> n >> p;
	matrix_t<double, 2> base, answer;
	base.val[1][1] = 1 - p; base.val[1][2] = p;
	base.val[2][1] = p; base.val[2][2] = 1 - p;
	answer = matrix_t<double, 2>::identity();
	for(; n>0; n>>=1, base=base*base) {
		if(n & 1) {
			answer = base * answer;
		}
	}
	cout << fixed << setprecision(9) << answer.val[1][1] << "\n";
	return 0;
}
