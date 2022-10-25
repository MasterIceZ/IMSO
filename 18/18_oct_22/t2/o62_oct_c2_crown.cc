#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MxN = 100010;
ll a[MxN], b[MxN], maxx = -1ll, sum = 0ll;
int n;

inline bool check(){
	int cnt_peak = 0;
	for(int i=1; i<=n; ++i){
		cnt_peak += (b[i] > b[i - 1] && b[i] > b[i + 1]);
	}
	return cnt_peak == 2;
}

void brute(int state){
	if(state == n + 1){
		bool ok = check();
		if(ok){
			sum = 0ll;
			for(int i=1; i<=n; ++i){
				sum = sum + b[i];
			}
			maxx = max(maxx, sum);
		}
		return ;
	}
	if(a[state] == 0){
		brute(state + 1);
	}
	else{
		for(int i=1; i<=a[state]; ++i){
			b[state] = i;
			brute(state + 1);
		}
	}
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	if(n <= 10){
		brute(1);
		cout << maxx << "\n";
		return 0;
	}
	ll max_hei = 0ll, sum_all = 0ll, cnt = 0ll;
	for(int i=1; i<=n; ++i){
		if(max_hei < a[i]){
			max_hei = a[i];
			cnt = 0;
		}
		if(max_hei == a[i]){
			cnt++;
		}
		sum_all += a[i];
	}
	if(cnt >= 3){
		cout << sum_all - (cnt - 2ll);
		return 0;
	}
	cout << -1;
	return 0;
}
