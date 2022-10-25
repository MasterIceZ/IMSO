#include "switches.h"
#include <bits/stdc++.h>

const int MxN = 50050;

long long a[MxN];
int jump[MxN];

struct fenwick_tree{
	long long tree[MxN];
	void build(int n){
		for(int i=1; i<=n; ++i){
			tree[i] = tree[i] + a[i];
			int idx = i & -i;
			if(i + idx <= 50000){
				tree[i + idx] = tree[i + idx] + tree[i];
			}
		}
	}
	long long query(int idx){
		long long res = 0ll;
		for(; idx; idx-=idx&-idx){
			res = res + tree[idx];
		}
		return res;
	}
} fw;

struct Line{
	int l, r;
	long long v;
	bool operator < (const Line& o) const {
		if(l != o.l){
			return l < o.l;
		}
		return r < o.r;
	}
	Line(int _l, int _r, long long _v):
		l(_l), r(_r), v(_v) {}
};

long long minimum_energy(int N, int M, int K, std::vector<int> A, std::vector<int> L, 
                         std::vector<int> R, std::vector<int> C){
	for(int i=1; i<=N; ++i){
		a[i] = (long long) A[i - 1];
	}
	fw.build(N);
	std::vector<Line> lines;
	for(int i=0; i<M; ++i){
		lines.emplace_back(L[i] + 1, R[i] + 1, C[i]);
	}
	std::sort(lines.begin(), lines.end());
	long long sum = 0ll;
	for(auto line: lines){
		long long sum_range = fw.query(line.r) - fw.query(line.l - 1);
		if(sum_range > line.v){
			sum = sum + line.v;
			jump[line.l] = line.r;
		}
	}
	for(int i=1; i<=N; ++i){
		if(jump[i]){
			i = jump[i];
			continue;
		}
		sum = sum + a[i];
	}
	return sum;
}
