#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stack>

const int MxN = 100010;
const int SQN = 500;
const int MxF = 200020;

template<typename T>
struct fenwick_tree {
	T *t;
	int n;

	fenwick_tree(int _n) {
		n = _n;
		t = (T *) calloc(n + 1, sizeof(T));
	}

	void clear() {
		for(int i=0; i<=n; ++i) {
			t[i] = T();
		}
	}
	
	void update(int idx, T v) {
		for(; idx<=n; idx+=idx&-idx) {
			t[idx] = std::max(t[idx], v);
		}
	}

	T query(int idx) {
		T res = T();
		for(; idx>0; idx-=idx&-idx) {
			res = std::max(res, t[idx]);
		}
		return res;
	}
};

int a[MxN], dp[SQN][MxN];

signed main(int argc, char* argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for(int i=1; i<=n; ++i) {
		std::cin >> a[i];
		dp[1][i] = i;
	}
	
	fenwick_tree<std::pair<int, int>> fw(MxF);
	for(int state=2; state<SQN; ++state) {
		for(int i=1; i<=n; ++i) {
			std::pair<int, int> v = fw.query(a[i] - 1);
			dp[state][i] = (v.first == 0 ? -1 : v.second);
			if(dp[state - 1][i] != -1) {
				int p = dp[state - 1][i];
				std::pair<int, int> to_update = std::make_pair(a[i], i);
				fw.update(2 * a[i] - a[p], to_update);
			}
		}
		fw.clear();
	}

	for(int l=SQN-1; l>=1; --l) {
		for(int i=1; i<=n; ++i) {
			if(dp[l][i] == -1) {
				continue;
			}

			std::stack<int> backtrack;
			int g = i;
			for(int j=l; j>=1; --j) {
				backtrack.emplace(g);
				g = dp[j][g];
			}
			std::cout << l << "\n";
			while(!backtrack.empty()) {
				std::cout << backtrack.top() << " ";
				backtrack.pop();
			}
			std::cout << "\n";

			goto EXIT;
		}
	}

EXIT:
	return 0;
}
