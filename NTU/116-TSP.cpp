#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

const int MxN = 11;
const int MxM = 110;
const int INF = 1e9 + 100;

int n, m, a[MxN][MxM], dp[MxN][MxM], track[MxN][MxM];

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	while(std::cin >> n >> m) {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=m; ++j) {
				std::cin >> a[i][j];
			}
		}

		memset(dp, 0x3f, sizeof dp);

		for(int i=1; i<=n; ++i) {
			dp[i][m] = a[i][m];
			track[i][m] = 0;
		}

		for(int j=m-1; j>=1; --j) {
			for(int i=1; i<=n; ++i) {
				int u = (i == 1) ? n : i - 1;
				int d = (i == n) ? 1 : i + 1;
				std::vector<int> dirs = {u, d, i};
				std::sort(dirs.begin(), dirs.end());

				int minn = INF, min_d = -1;
				for(auto d: dirs) {
					if(minn > dp[d][j + 1]) {
						minn = dp[d][j + 1];
						min_d = d;
					}
					else if(minn == dp[d][j + 1]) {
						min_d = std::min(min_d, d);
					}
				}

				dp[i][j] = a[i][j] + minn;
				track[i][j] = min_d;
			}
		}

		int answer = INF, track_pos = -1;
		for(int i=1; i<=n; ++i) {
			if(answer > dp[i][1]) {
				answer = dp[i][1];
				track_pos = i;
			}
			else if(answer == dp[i][1]) {
				track_pos = std::min(track_pos, i);
			}
		}
	
		std::cout << track_pos;
		for(int j=1; j<m; ++j) {
			track_pos = track[track_pos][j];
			std::cout << " " << track_pos;
		}

		std::cout << "\n" << answer << "\n";
	}
	return 0;
}
