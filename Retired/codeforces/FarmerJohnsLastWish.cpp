#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <vector>

const int MxN = 200020;

std::vector<int> divisors[MxN];
int a[MxN], count_div[MxN];
std::bitset<MxN> solving;

inline void solve() {
	int n;
	std::cin >> n;
	for(int i=1; i<=n; ++i) {
		std::cin >> a[i];
	}
	memset(count_div, 0, sizeof count_div);
	solving = 0;

	int cur_answer = 0;
	std::vector<int> to_solve;
	for(int i=1; i<=n; ++i) {
		std::vector<int> solve_next;
		for(auto d: divisors[a[i]]) {
			count_div[d] += 1;
			if(count_div[d] != i) {
				cur_answer = std::max(cur_answer, count_div[d]);
			}
			else if(!solving[d]) {
				solve_next.emplace_back(d);
				solving[d] = true;
			}
		}


		for(auto s: to_solve) {
			if(count_div[s] != i) {
				cur_answer = std::max(cur_answer, count_div[s]);
				solving[s] = false;
			}
			else {
				solve_next.emplace_back(s);
			}
		}
		to_solve = solve_next;
		std::cout << cur_answer << " ";
	}
	std::cout << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

	for(int i=2; i<MxN; ++i) {
		for(int j=i; j<MxN; j+=i) {
			divisors[j].emplace_back(i);
		}
	}

	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
