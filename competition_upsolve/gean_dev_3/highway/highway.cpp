#include "highway.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T, size_t S>
struct matrix_t:array<array<T, S + 1>, S + 1> {
	matrix_t() {
		for(int i=1; i<=(int) S; ++i) {
			for(int j=1; j<=(int) S; ++j) {
				(*this)[i][j] = 1e18 + 100ll;
			}
		}
	}
	static constexpr matrix_t identity() {
		matrix_t res;
		for(int i=1; i<=(int) S; ++i) {
			res[i][i] = 0ll;
		}
		return res;
	}
	matrix_t operator * (const matrix_t& o) {
		matrix_t res;
		for(int i=1; i<=(int) S; ++i) {
			for(int j=1; j<=(int) S; ++j) {
				for(int k=1; k<=(int) S; ++k) {
					res[i][j] = min(res[i][j], *(this)[i][k] + o[k][j]);
				}
			}
		}
		return res;
	}
};

int n;
vector<int> a, b, c;

void init(int N, int Q, std::vector<int> A, std::vector<int> B, std::vector<int> C) {
	n = N;
	a = A;
	b = B;
	c = C;
  return;
}

void update(int X, int Y, int Z) {
  a[X] = Y;
  b[X] = Z;
  return;
}

long long query(int S, int T) {
  return min(a[0], b[0] + c[0]);
}
