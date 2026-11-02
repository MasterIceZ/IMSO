#include <algorithm>
#include <iostream>

const int MxN = 1010;
const int INF = 1e9 + 100;

int qs[MxN][MxN];

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

	int n;
	while(std::cin >> n) {
		for(int i=1; i<=n; ++i) {
			for(int j=1, x; j<=n; ++j) {
				std::cin >> x;
				qs[i][j] = x + qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1];
			}
		}
		
		int answer = -INF;
		for(int a=1; a<=n; ++a) {
			for(int b=1; b<=n; ++b) {
				for(int c=a; c<=n; ++c) {
					for(int d=b; d<=n; ++d) {
						answer = std::max(answer, qs[c][d] - qs[a - 1][d] - qs[c][b - 1] + qs[a - 1][b - 1]);
					}
				}
			}
		}
		
		std::cout << answer << "\n";
	}

	return 0;
}
