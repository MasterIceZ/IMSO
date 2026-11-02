#include <bitset>
#include <iostream>
#include <vector>

const int MxN = 22;
const int MxK = 1010;

std::bitset<MxN * MxN> a[MxK], b, c;

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, k;
	std::cin >> n >> k;
	n = n * n;
	for(int i=1; i<=k; ++i) {
		for(int j=0, x; j<n; ++j) {
			std::cin >> x;
			a[i][j] = x;
		}
	}
	for(int i=0, x; i<n; ++i) {
		std::cin >> x;
		b[i] = x;
	}
	std::vector<int> answer;
	for(int i=1; i<=k; ++i) {
		if((a[i] | b) != b) {
			continue;
		}
		answer.emplace_back(i);
		c |= a[i];
	}
	if(c != b) {
		std::cout << "-1\n";
		return 0;
	}
	std::cout << answer.size() << "\n";
	for(auto x: answer) {
		std::cout << x << " ";
	}
	std::cout << "\n";
}
