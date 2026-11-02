#include <cmath>
#include <cstring>
#include <iostream>
#include <numeric>

const int MxN = 1000010;

bool done[MxN];

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n;
	while(std::cin >> n) {
		memset(done, false, sizeof done);

		int sq = std::sqrt(n), cnt = 0;
		for(int i=1; i<=sq; ++i) {
			int rsq = std::sqrt(n - i * i);
			rsq = std::min(rsq, sq);

			for(int j=i+1; j<=rsq; ++j) {
				if(i % 2 == j % 2 || std::gcd(i, j) != 1) {
					continue;
				}
				cnt++;
				int a = 2 * i * j;
				int b = j * j - i * i;
				int c = j * j + i * i;
				
				for(int k=0; k*c<=n; ++k) {
					done[a * k] = true;
					done[b * k] = true;
					done[c * k] = true;
				}
			}
		}

		int r = 0;
		for(int i=1; i<=n; ++i) {
			r += (!done[i]);
		}
		std::cout << cnt << " " << r << "\n";
	}
	return 0;
}
