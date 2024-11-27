#include <bits/stdc++.h>

using namespace std;

const int MxD = 7;
const int MxH = 24;

string s[MxD];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	for(int i=0; i<MxD; ++i) {
		cin >> s[i];
	}	
	int wd, wh;
	cin >> wd >> wh;
	int max_mask=(1 << MxD);
	double answer = 0.0;
	for(int mask=0; mask<max_mask; ++mask) {
		if(__builtin_popcount(mask) != wd) {
			continue;
		}
		vector<int> count_avail(MxH);
		for(int d=0; d<MxD; ++d) {
			for(int h=0; h<MxH; ++h) {
				int cur_mask = (1 << d);
				if(!(mask & cur_mask) || s[d][h] == 'x') {
					continue;
				}
				count_avail[h]++;
			}
		}
		sort(count_avail.begin(), count_avail.end(), greater<int> ());
		answer = max(answer, (double) (accumulate(count_avail.begin(), count_avail.begin() + wh, 0.0)) / ((double) wd * wh));
	}
	cout << fixed << setprecision(7) << answer << "\n";
	return 0;
}
