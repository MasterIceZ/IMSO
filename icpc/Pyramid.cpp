#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

int a[MxN], from_front[MxN], from_back[MxN];

int main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i) {
		if(a[i] > from_front[i - 1]) {
			from_front[i] = from_front[i - 1] + 1;
		}
		else {
			from_front[i] = a[i];
		}
	}
	for(int i=n; i>=1; --i) {
		if(a[i] > from_back[i + 1]) {
			from_back[i] = from_back[i + 1] + 1;
		}
		else {
			from_back[i] = a[i];
		}
	}
	int answer = 0;
	for(int i=1; i<=n; ++i) {
		//cerr << from_front[i] << " " << from_back[i] << "\n";
		answer = max(answer, min(from_front[i], from_back[i]));
	}
	cout << answer << "\n";
	return 0;
}
