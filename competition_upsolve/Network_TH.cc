#include <bits/stdc++.h>

using namespace std;

using ll = long long;
map<ll, ll> mp;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	ll m, l, r, x;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> l >> r >> x;
		mp[l] += x;
		mp[r + 1] -= x;
	}
	vector<pair<int, int>> answer = {{0, 0}};
	ll current_sum = 0ll;
	for(auto x: mp){
		current_sum += x.second;
		if(current_sum > m && answer.back().second == -1){
			continue;
		}
		else if(current_sum > m){
			answer.emplace_back(x.first, -1);
		}
		else if(current_sum <= m && answer.back().second == -1){
			answer[answer.size() - 1].second = x.first - 1;
		}
	}
	for(int i=1; i<(int) answer.size(); ++i){
		cout << answer[i].first << " " << answer[i].second << "\n";
	}
	return 0;
}
