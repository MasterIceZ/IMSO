#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

const int MxN = 200020;

template<typename T>
struct fenwick_tree {
	T *t;
	int n;

	fenwick_tree(int _n) {
		n = _n;
		t = (T *) calloc(n + 1, sizeof(T));
	}
	
	void update(int idx, T v) {
		for(; idx<=n; idx+=idx&-idx) {
			t[idx] += v;
		}
	}

	T query(int idx) {
		T res = T();
		for(; idx>0; idx-=idx&-idx) {
			res += t[idx];
		}
		return res;
	}
};

int perm[MxN], pos[MxN];

signed main(int argc, char* argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	fenwick_tree<int> fw(n);
	for(int i=1; i<=n; ++i) {
		std::cin >> perm[i];
		pos[perm[i]] = i;
		fw.update(i, 1);
	}
	int l = 1;
	std::vector<int> mem;
	for(int i=n; i>=1; --i) {
		int cur = -1;
		if(pos[i] >= l) {
			cur= fw.query(pos[i]) - fw.query(l - 1);
		}
		else {
			cur = fw.query(n) - fw.query(l - 1) + fw.query(pos[i]);
		}
		mem.emplace_back(i + 1 - cur);
		fw.update(pos[i], -1);
		if(pos[i] == n) {
			l = 1;
		}
		else {
			l = pos[i] + 1;
		}
	}

	std::reverse(mem.begin(), mem.end());
	for(auto a: mem) {
		std::cout << a << " ";
	}
	std::cout << "\n";
	return 0;
}
