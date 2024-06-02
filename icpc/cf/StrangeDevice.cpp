#include <bits/stdc++.h>

using namespace std;

int n, k;
map<int, int> mp;

inline pair<int, int> ask(int it) {
	cout << "?";
	for(int i=1; i<=k+1; ++i) {
		if(i == it) {
			continue;
		}
		cout << " " << i;
	}
	cout << endl;
	pair<int, int> res;
	cin >> res.first >> res.second;
	return res;
}

signed main(int argc, char *argv[]) {
	cin >> n >> k;
	for(int i=1; i<=k+1; ++i) {
		pair<int, int> a = ask(i);
		mp[a.second]++;
	}
	cout << "! " << (++mp.begin())->second << endl;
	return 0;
}
