#include <bits/stdc++.h>

using namespace std;

const int MxN = 12;
const double INF = 1e18;

pair<double, double> p[MxN];
double dist[MxN][MxN];
double dp[1 << MxN][MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> p[i].first >> p[i].second;
	}

	auto find_dist = [&](pair<double, double> a, pair<double, double> b, double angle) {
		return abs(a.first - b.first) + abs(a.second - b.second);
	};

	auto try_angle = [&](double angle) {
		for(int i=0; i<n; ++i) {
			for(int j=i+1; j<n; ++j) {
				dist[i][j] = dist[j][i] = find_dist(p[i], p[j], angle);
			}
		}
		int max_mask = (1 << n);
		for(int mask=0; mask<max_mask; ++mask) {
			for(int i=0; i<n; ++i) {
				dp[mask][i] = INF;
			}
		}
		for(int i=0; i<n; ++i) {
			int cur_mask = (1 << i);
			dp[cur_mask][i] = 0;
		}
		for(int mask=0; mask<max_mask; ++mask) {
			for(int from=0; from<n; ++from) {
				int with_from = (1 << from);
				if(!(mask & with_from)) {
					continue;
				}
				for(int to=0; to<n; ++to) {
					int with_to = (1 << to);
					if(mask & with_to) {
						continue;
					}
					int mask_with_to = (mask | with_to);
					dp[mask_with_to][to] = min(dp[mask_with_to][to], dp[mask][from] + dist[from][to]);
				}
			}
		}
		return *min_element(dp[max_mask - 1], dp[max_mask - 1] + n);
	};

	double answer = INF;
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			double angle = 0;
			double cur_dist = try_angle(angle);
			answer = min(answer, cur_dist);
		}
	}
	cout << fixed << setprecision(7) << answer << "\n";
	return 0;
}
