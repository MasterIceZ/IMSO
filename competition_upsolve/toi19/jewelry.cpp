#include <iostream>
#include <stack>
#include <numeric>

using namespace std;

using ll = long long;

struct jew_t{
	ll cnt;
	int last_idx;
	jew_t(ll _cnt, int _last_idx):
		cnt(_cnt), last_idx(_last_idx) {}
};

const int MxN = 1000010;
stack<jew_t> st;
ll dp[MxN];

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	s = " " + s;
	if(s[1] == 'T'){
		dp[1] = 1;
		st.emplace(1, 1);
	}
	for(int i=2; i<=n; ++i){
		if(s[i] == 'F'){
			dp[i] = dp[i - 1];
		}
		else{
			jew_t nxt_jew(1ll, i);
			if(s[i - 1] == 'T'){
				nxt_jew = st.top(); st.pop();
				nxt_jew.cnt = nxt_jew.cnt + 1ll;
				nxt_jew.last_idx = i;
			}
			while(!st.empty() && st.top().cnt < nxt_jew.cnt){
				st.pop();
			}
			if(st.empty()){
				dp[i] = dp[i - 1] + (ll) (i);
			}
			else{
				dp[i] = dp[i - 1] + (ll) (i) - st.top().last_idx + nxt_jew.cnt - 1ll;
			}
			st.emplace(nxt_jew);
		}
	}
	cout << accumulate(dp + 1, dp + n + 1, 0ll);
	return 0;
}
