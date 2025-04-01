#include "eatingfish.h"

#include <vector>
#include <algorithm>
#include <iostream>

const int MxN = 300030;

int N;
long long a[MxN];

struct segment_tree {
	long long t[MxN << 2];
	void build(int l, int r, int idx, long long *a) {
		if(l > r) {
			return ;
		}
		if(l == r) {
			t[idx] = a[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1, a);
		build(mid + 1, r, idx << 1 | 1, a);
		t[idx] = std::max(t[idx << 1], t[idx << 1 | 1]);
	}
	void update(int l, int r, int id, long long v, int idx) {
		if(l > r || l > id || r < id) {
			return ;
		}
		if(l == r) {
			t[idx] = v;
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, v, idx << 1);
		update(mid + 1, r, id, v, idx << 1 | 1);
		t[idx] = std::max(t[idx << 1], t[idx << 1 | 1]);
	}
	int search_right_most(int l, int r, int wl, int wr, long long v, int idx) {
		if(l > r || l > wr || r < wl || t[idx] <= v) {
			return 0;
		}
		if(l == r) {
			return l;
		}
		int mid = (l + r) >> 1;
		int res = search_right_most(mid + 1, r, wl, wr, v, idx << 1 | 1);
		if(res == 0) {
			res = search_right_most(l, mid, wl, wr, v, idx << 1);
		}
		return res;
	}
	int search_left_most(int l, int r, int wl, int wr, long long v, int idx) {
		if(l > r || l > wr || r < wl || t[idx] <= v) {
			return N + 1;
		}
		if(l == r) {
			return l;
		}
		int mid = (l + r) >> 1;
		int res = search_left_most(l, mid, wl, wr, v, idx << 1);
		if(res == N + 1) {
			res = search_left_most(mid + 1, r, wl, wr, v, idx << 1 | 1);
		}
		return res;
	}
} seg;

struct fenwick_tree {
	int N;
	long long t[MxN];
	void build(int _N, long long *a) {
		N = _N;
		for(int i=1; i<=N; ++i) {
			t[i] += a[i];
			int nxt = i + (i & -i);
			if(nxt <= N) {
				t[nxt] += t[i];
			}	
		}
	}
	void update(int idx, long long v) {
		for(; idx<=N; idx+=idx&-idx) {
			t[idx] += v;
		}
	}
	long long query(int idx) {
		long long res = 0ll;
		for(; idx>0; idx-=idx&-idx) {
			res += t[idx];
		}
		return res;
	}
} fw;

inline long long cal_sz(int l, int r) {
	return fw.query(r) - fw.query(l - 1);
}

void init_fish(int N, std::vector<int> S) {
	::N = N;
	for(int i=1; i<=N; ++i) {
		a[i] = S[i - 1];
	}	
	fw.build(N, a);
	seg.build(1, N, 1, a);
}

void cast_magic(int P, int V) {
	P++;
	long long to_update = V - a[P];
	fw.update(P, to_update);
	a[P] = V;
	seg.update(1, N, P, V, 1);
}

long long eat_friend(int P, int L, int R) {
	P++;
	L++, R++;
	int l = P, r = P;
	while(true) {
		int pre_l = l, pre_r = r;
		l = std::max(L, seg.search_right_most(1, N, 1, l - 1, cal_sz(l, r), 1) + 1);
		r = std::min(R, seg.search_left_most(1, N, r + 1, N, cal_sz(l, r), 1) - 1);
		if(pre_l == l && pre_r == r) {
			break;
		}
	}
	return cal_sz(l, r);
}
