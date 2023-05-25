#include <vector>
#include "stairs.h"

struct Matrix{
	long long mtx[110][110];
	Matrix() {
		for(int i=0; i<110; ++i){
			for(int j=0; j<110; ++j){
				mtx[i][j] = 0ll;
			}
		}
	}
} a, lift;

const long long MOD = 1e9 + 7;

Matrix operator * (Matrix A, Matrix B){
	Matrix C;
	for(int i=0; i<100; ++i){
		for(int j=0; j<100; ++j){
			for(int k=0; k<100; ++k){
				C.mtx[i][j] = (C.mtx[i][j] + ((A.mtx[i][k] * B.mtx[k][j]) % MOD)) % MOD;
			}
		}
	}
	return C;
};

int countWays(long long N, int M, std::vector<int> S){
	a.mtx[0][0] = 1ll;
	for(int i=1; i<100; ++i){
		lift.mtx[i][i - 1] = 1ll;
	}
	for(auto x: S){
		lift.mtx[0][x - 1] = 1ll;
	}
	for(; N != 0; N >>= 1ll, lift = lift * lift) {
		if(N & 1ll){
			a = lift * a;
		}
	}
    return a.mtx[0][0];
}
