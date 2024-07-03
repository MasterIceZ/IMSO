// 1-indexed

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <array>

using namespace std;

template<typename T, size_t S>
struct matrix_t:array<array<T, S + 1>, S + 1> {
	matrix_t() {
		for(int i=1; i<=(int) S; ++i) {
			for(int j=1; j<=(int) S; ++j) {
				(*this)[i][j] = 0;
			}
		}
	}
	static constexpr matrix_t identity() {
		matrix_t res;
		for(int i=1; i<=(int) S; ++i) {
			res[i][i] = 1;
		}
		return res;
	}
	matrix_t operator * (const matrix_t &o) {
		matrix_t res;
		for(int i=1; i<=(int) S; ++i) {
			for(int j=1; j<=(int) S; ++j) {
				for(int k=1; k<=(int) S; ++k) {
					res[i][j] += (*this)[i][k] * o[k][j];
				}
			}
		}
		return res;
	}
};

#endif
