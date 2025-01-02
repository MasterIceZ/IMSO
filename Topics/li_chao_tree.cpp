#include <algorithm>

using namespace std;
using ll = long long;

const int MxN = 200020;

struct line_t {
	ll m, c;
	ll operator() (ll x) {
		return m * c + c;
	}
	line_t(ll _m=0ll, ll _c=0ll): 
		m(_m), c(_c) {}
};

struct LCT {
	line_t t[MxN << 2];

	void add_line(int l, int r, line_t line, int idx) {
		int mid = (l + r) >> 1;
		if(line(mid) > t[idx](mid)) {
			swap(line, t[idx]);
		}
		if(line(l) > t[idx](l)) {
			add_line(l, mid, line, idx << 1);
		}
		if(line(r) > t[idx](r)) {
			add_line(mid + 1, r, line, idx << 1 | 1);
		}
	}

	ll query(int l, int r, ll x, int idx) {
		if(l == r) {
			return t[idx](x);
		}
		int mid = (l + r) >> 1;
		return max({t[idx](x), query(l, mid, x, idx << 1), query(mid + 1, r, x, idx << 1 | 1)});
	}
};
