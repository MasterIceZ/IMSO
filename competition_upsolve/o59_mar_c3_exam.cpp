#include <bits/stdc++.h>

using namespace std;

const int MxN = 50050;
const int SqN = 233;

struct query_t {
	int l, r, idx;
	bool operator < (const query_t &o) const {
		return r < o.r;
	}
	query_t(int _l, int _r, int _idx):
		l(_l), r(_r), idx(_idx) {}
};

unordered_map<int, int> number_idx;
int a[MxN], answer_vector[MxN], cnt[MxN];
vector<query_t> cluster[SqN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n;

	vector<int> c;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}

	int unique_numbers = 0;
	for(int i=1; i<=n; ++i) {
		if(number_idx.find(a[i]) == number_idx.end()) {
			number_idx[a[i]] = ++unique_numbers;
		}
		a[i] = number_idx[a[i]];
	}
	
	cin >> q;
	int sq = sqrt(n);
	for(int i=1, l, h; i<=q; ++i) {
		cin >> l >> h;
		l++, h++;
		cluster[l / sq].emplace_back(l, h, i);
	}

	int answer = 0;
	auto remove = [&](int idx) {
		answer -= (cnt[a[idx]] >= 2);
		cnt[a[idx]]--;
	};
	auto add = [&](int idx) {
		cnt[a[idx]]++;
		answer += (cnt[a[idx]] >= 2);
	};

	for(int i=0; i<SqN; ++i) {
		if(cluster[i].empty()) {
			continue;
		}

		sort(cluster[i].begin(), cluster[i].end());
		int l = cluster[i][0].l;
		int r = cluster[i][0].l;
		for(int j=1; j<=unique_numbers; ++j) {
			cnt[j] = 0;
		}
		cnt[a[l]]++;
		answer = 0;

		for(auto query: cluster[i]) {
			while(l < query.l) {
				remove(l++);
			}
			while(l > query.l) {
				add(--l);
			}
			while(r < query.r) {
				add(++r);
			}
			answer_vector[query.idx] = answer;
		}
	}

	for(int i=1; i<=q; ++i) {
		cout << answer_vector[i] << "\n";
	}

	return 0;
}
