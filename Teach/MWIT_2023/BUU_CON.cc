#include <bits/stdc++.h>
using namespace std;

using ll = long long;

priority_queue<ll> pq;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int d, n, b;
	ll k, sum = 0, x;
	cin >> d >> k;
	for(int i=1; i<=d; ++i){
		cin >> n >> b;
		for(int j=1; j<=n; ++j){
			cin >> x;
			pq.emplace(x - i * k);
		}
		while(!pq.empty() && b--){
			sum += pq.top() + i * k; pq.pop();
		}
	}
	cout << sum;
	return 0;
}
