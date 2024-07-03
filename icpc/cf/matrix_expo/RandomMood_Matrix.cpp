#include <bits/stdc++.h>

using namespace std;

template<typename T, size_t S>
struct matrix_t {
	array<array<T, S + 1>, S + 1> val;
	matrix_t() {
		for(int i=1; i<=(int) S; ++i) {
			for(int j=1; j<=(int) S; ++j) {
				val[i][j] = 0;
			}
		}
	}
	static constexpr matrix_t identity() {
		matrix_t res;
		for(int i=1; i<=(int) S; ++i) {
			res.val[i][i] = 1;
		}
		return res;
	}
	matrix_t operator * (const matrix_t &o) {
		matrix_t res;
		for(int i=1; i<=(int) S; ++i) {
			for(int j=1; j<=(int) S; ++j) {
				for(int k=1; k<=(int) S; ++k) {
					res.val[i][j] += val[i][k] * o.val[k][j];
				}
			}
		}
		return res;
	}
};

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
