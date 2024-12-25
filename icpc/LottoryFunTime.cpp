#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;
const int TWO = 100;
const int FOUR = 10000;
const long long FIRST_PRIZE = 300000ll;
const long long SECOND_PRIZE = 4000ll;
const long long THIRD_PRIZE = 500ll;

long long cnt_two[TWO], cnt_four[FOUR], cnt_four_two[TWO];

signed main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	for(int i=1, v; i<=n; ++i) {
		scanf("%d", &v);
		cnt_two[v % TWO]++;
		cnt_four[v % FOUR]++;
	}
	for(int i=0; i<FOUR; ++i) {
		cnt_four_two[i % TWO] = max(cnt_four_two[i % TWO], cnt_four[i]);
	}
	vector<pair<long long, int>> v;
	for(int i=0; i<TWO; ++i) {
		v.emplace_back(cnt_two[i], i);
	}
	sort(v.begin(), v.end(), greater<pair<long long, int>> ());
	long long answer = 0ll;
	for(int i=0; i<TWO; ++i) {
		for(int j=0; j<TWO; ++j) {
			if(i == j) {
				continue;
			}
			long long cur_answer = 0ll;
			if(cnt_two[i] > 0ll) {
				cur_answer += FIRST_PRIZE;
			}
			cur_answer += SECOND_PRIZE * cnt_four_two[j];
			int cnt = 0;
			for(auto x: v) {
				if(x.second == i || x.second == j) {
					continue;
				}
				cur_answer += THIRD_PRIZE * x.first;
				if(++cnt == 3) {
					break;
				}
			}
			answer = max(answer, cur_answer);
		}
	}
	printf("%lld\n", answer);
	return 0;
}
