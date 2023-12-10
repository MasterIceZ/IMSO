#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if(k < n / 2 || n == k) {
		cout << "-1\n";
		return 0;
	}
	deque<char> d;
	for(int i=1; i<=n/2; ++i) {
		d.emplace_front('(');
		d.emplace_back(')');
	}
	int cnt_front = 0, cnt_back = 0;
	k -= n / 2 - 1;
	for(int i=1; i<=k-1; ++i) {
		d.pop_front();
		d.pop_back();
		if(i % 2) {
			cnt_front++;
		}
		else {
			cnt_back++;
		}
	}
	while(cnt_front--) {
		cout << "()";
	}
	for(auto x: d) {
		cout << ((char) x);
	}
	while(cnt_back--) {
		cout << "()";
	}
	cout << "\n";
	return 0;
}
