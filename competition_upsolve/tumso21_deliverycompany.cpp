#include <bits/stdc++.h>

using namespace std;

set<int> day_set;
priority_queue<int, vector<int>, greater<int>> days, pq;
map<int, vector<int>> day_ok;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, max_days = 0;
	cin >> n;
	for(int i=1, l, r; i<=n; ++i) {
		cin >> l >> r;
		day_ok[l].emplace_back(r);
		day_set.emplace(l);
		day_set.emplace(r);
		max_days = max(max_days, r);
	}
	for(auto d: day_set) {
		days.emplace(d);
	}
	int answer = 0;
	while(!days.empty()) {
		int cur_day = days.top();
		days.pop();
		if(cur_day > max_days) {
			break;
		}
		while(!pq.empty() && pq.top() < cur_day) {
			pq.pop();
		}
		if(day_ok.count(cur_day) == false && pq.empty()) {
			days.emplace(cur_day + 1);
			continue;
		}
		for(auto x: day_ok[cur_day]) {
			pq.emplace(x);
		}
		if(!pq.empty()) {
			answer += 1;
			pq.pop();
		}
	}
	cout << answer << "\n";
	return 0;
}
