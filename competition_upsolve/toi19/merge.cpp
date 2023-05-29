#include <iostream>
#include <climits>

using namespace std;

using ll = long long;

const int MxN = 100010;

int n, m;
ll a, b, k, x, pos_x[MxN], pos_y[MxN], sum_x[MxN], sum_y[MxN];

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	pos_x[0] = LLONG_MIN; pos_y[0] = LLONG_MIN;
	pos_x[n + 1] = LLONG_MAX; pos_y[m + 1] = LLONG_MAX;
	for(int i=1; i<=n; ++i){
		cin >> pos_x[i];
	}
	for(int i=1; i<=n; ++i){
		cin >> sum_x[i];
		sum_x[i] = sum_x[i] + sum_x[i - 1];
	}
	sum_x[n + 1] = sum_x[n];
	for(int i=1; i<=m; ++i){
		cin >> pos_y[i];
	}
	for(int i=1; i<=m; ++i){
		cin >> sum_y[i];
		sum_y[i] = sum_y[i] + sum_y[i - 1];
	}
	sum_y[m + 1] = sum_y[m];
	auto cnt_x = [&](ll idx){
		ll l = 0, r = n;
		while(l < r){
			ll mid = (l + r + 1ll) >> 1ll;
			if(pos_x[mid] <= idx){
				l = mid;
			}
			else{
				r = mid - 1ll;
			}
		}
		return sum_x[l];
	};
	auto cnt_y = [&](ll idx){
		ll l = 0, r = m;
		while(l < r){
			ll mid = (l + r + 1ll) >> 1ll;
			if(pos_y[mid] * a + b <= idx){
				l = mid;
			}
			else{
				r = mid - 1ll;
			}
		}
		return sum_y[l];
	};
	while(q--){
		cin >> a >> b >> k;
		ll l = -1e9, r = 1e9;
		while(l < r){
			ll mid = (l + r) >> 1ll;
			if(cnt_x(mid) + cnt_y(mid) >= k){
				r = mid;
			}
			else{
				l = mid + 1ll;
			}
		}
		cout << l << "\n";
	}
	return 0;
}
