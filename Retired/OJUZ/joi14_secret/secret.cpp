#include "secret.h"

const int MxN = 1010;
const int MxL = 22;

int a[MxN], mem[MxL][MxN], state[MxN];

void solve(int l, int r, int lvl) {
	if(l >= r) {
		return ;
	}
	int mid = (l + r) >> 1;
	mem[lvl][mid] = a[mid];
	for(int i=mid-1; i>=l; --i) {
		mem[lvl][i] = Secret(a[i], mem[lvl][i + 1]);
	}
	mem[lvl][mid + 1] = a[mid + 1];
	for(int i=mid+2; i<=r; ++i) {
		mem[lvl][i] = Secret(mem[lvl][i - 1], a[i]);
	}
	for(int i=mid+1; i<=r; ++i) {
		state[i] ^= (1 << lvl);
	}
	solve(l, mid, lvl + 1);
	solve(mid + 1, r, lvl + 1);
}

void Init(int N, int A[]) {
	for(int i=1; i<=N; ++i) {
		a[i] = A[i - 1];
	}
	solve(1, N, 0);
}

int Query(int L, int R) {
	L++, R++;
	if(L == R) {
		return a[L];
	}
	int mask = __builtin_ctz(state[L] ^ state[R]);
	return Secret(mem[mask][L], mem[mask][R]);
}
