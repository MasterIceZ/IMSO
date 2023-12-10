#include <bits/stdc++.h>

using namespace std;

string s[10];

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	string answer = "ZZZ";
	for(int i=1; i<=3; ++i) {
		cin >> s[i];
		s[i] = " " + s[i];
	}
	vector<string> v;
	for(int a=1; a<=3; ++a) {
		for(int b=1; b<=3; ++b) {
			for(int c=1; c<=3; ++c) {
				for(int d=1; d<=3; ++d) {
					for(int e=1; e<=3; ++e) {
						for(int f=1; f<=3; ++f) {
							if(make_pair(a, b) == make_pair(c, d) || make_pair(c, d) == make_pair(e, f) || make_pair(e, f) == make_pair(a, b)) {
								continue;
							}
							if(abs(a - c) <= 1 && abs(b - d) <= 1 && abs(c - e) <= 1 && abs(d - f) <= 1) {
								string t{s[a][b], s[c][d], s[e][f]};
								v.emplace_back(t);
							}
						}
					}
				}
			}
		}
	}
	cout << *min_element(v.begin(), v.end()) << "\n";
	return 0;
}
