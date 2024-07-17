#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

int s[MxN], f[MxN], most_r[MxN];
pair<int, int> backtrack[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> s[i];
	}
	for(int i=1; i<=m; ++i) {
		cin >> f[i];
	}
	f[m + 1] = 1e9 + 100;

	auto go_next = [&](int idx) {
		return upper_bound(f + 1, f + m + 2, idx) - (f + 1);
	};

	auto check = [&](int x) {
		for(int i=1; i<=n; ++i) {
			if(f[most_r[i - 1] + 1] < s[i] - x) {
				// cannot cover
				return false;
			}
			if(f[most_r[i - 1] + 1] >= s[i]) {
				// over this
				most_r[i] = go_next(s[i] + x);
				backtrack[i] = make_pair(i - 1, 2);
			}
			else {
				// this have to go left
				most_r[i] = go_next(s[i]);
				backtrack[i] = make_pair(i - 1, 1);
			}
			if(i >= 2 && f[most_r[i - 2] + 1] >= s[i] - x && most_r[i] < go_next(s[i - 1] + x)) {
				most_r[i] = go_next(s[i - 1] + x);
				backtrack[i] = make_pair(i - 2, 3);
			}
		}
		return most_r[n] >= m;
	};

	int l = 0, r = 1e9 + 100;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	if(!check(l)) {
		cout << "-1\n";
		return 0;
	}
	cout << l << "\n";
	int cur_pos = n;
	vector<int> answer;
	while(cur_pos != 0) {
		answer.emplace_back(backtrack[cur_pos].second);
		cur_pos = backtrack[cur_pos].first;
	}
	reverse(answer.begin(), answer.end());
	for(auto x: answer) {
		if(x == 2 || x == 3) {
			cout << "R";
		}
		if(x == 1 || x == 3) {
			cout  << "L";
		}
	}
	cout << "\n";
	return 0;
}
