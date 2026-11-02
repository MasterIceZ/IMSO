#include <algorithm>
#include <cstring>
#include <iostream>

const int MxK = 11;
const int MxN = 33;

int boxes[MxN][MxK], maxx;
int n, k, mem[MxN], answer[MxN], sv[MxN];

inline bool good(int x, int y) {
	bool ok = true;
	for(int i=1; i<=k; ++i) {
		ok &= (boxes[x][i] < boxes[y][i]);
	}
	return ok;
}

void dfs(int cur, int x) {
	for(int i=1; i<=n; ++i) {
		if(i == cur || !good(cur, i) || mem[i] >= x + 1) {
			continue;
		}
		mem[i] = x + 1;
		sv[x] = i;
		dfs(i, x + 1);
	}
	if(maxx < x) {
		maxx = x;
		for(int i=0; i<maxx; ++i) {
			answer[i] = sv[i];
		}
	}
}

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	while(std::cin >> n >> k) {
		memset(mem, 0, sizeof mem);
		memset(answer, 0, sizeof answer);
		memset(sv, 0, sizeof sv);
		maxx = 0;

		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=k; ++j) {
				std::cin >> boxes[i][j];
			}
			std::sort(boxes[i] + 1, boxes[i] + k + 1);
		}
		dfs(0, 0);
		std::cout << maxx << "\n";
		for(int i=0; i<maxx; ++i) {
			std::cout << answer[i] << " \n"[i == maxx - 1];
		}
	}
	return 0;
}
