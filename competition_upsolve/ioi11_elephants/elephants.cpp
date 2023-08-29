#include "elephants.h"

const int MxN = 150050;
const int SQ = 390;

int n, l, x[MxN];
vector<int> elephant[SQ];

inline void buildBlock(int block) {
	int n = elephant[block].size();
	for(int i=n-1, cur=n-1; i>=0; --i) {
		while(elephant[block][cur] - elephant[block][i] > l) {
			cur--;
		}
		count[
	}
}

inline void build() {
	sort(x, x + n);
	for(int i=0; i<SQ; ++i) {
		elephant[i].clear();
	}
	for(int i=0; i<=n-1; ++i) {
		int block = i / SQ;
		elephant[block].emplace_back(x[i]);
	}
	for(int i=0; i<SQ; ++i) {
		buildBlock(i);
	}
}

void init(int N, int L, int X[])
{
	n = N;
	l = L;
	for(int i=0; i<=n-1; ++i) {
		x[i] = X[i];
	}
	build();
}

int update(int i, int y)
{
  return n;
}
