#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;

struct line_t{
	ll l, r;
	int idx;
	bool operator < (const line_t& o) const {
		if(l != o.l){
			return l > o.l;
		}
		return r < o.r;
	}
	line_t(ll _l, ll _r, int _idx):
		l(_l), r(_r), idx(_idx) {}
};

const int MxN = 400040;
vector<line_t> line;
ll l, r, dp[MxN], mem[MxN];

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> l >> r;
		line.emplace_back(l, r, i);
	}
	sort(line.begin(), line.end());
	int sz = 0;
	for(int i=0; i<n; ++i){
		int idx = upper_bound(dp, dp + sz, line[i].r) - dp;
		if(idx == sz){
			sz++;
			mem[line[i].idx] = sz;
		}
		else{
			mem[line[i].idx] = idx + 1;
		}
		dp[idx] = line[i].r;
	}
	cout << *max_element(mem + 1, mem + n + 1) << "\n";
	for(int i=1; i<=n; ++i){
		cout << mem[i] << " ";
	}
	return 0;
}
