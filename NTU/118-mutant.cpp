#include <iostream>
#include <string>

const int MxN = 55;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char FACES[] = "NESW";

bool scent[MxN][MxN];
int n, m, x, y, d;

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

	std::cin >> n >> m;

	char f;
	while(std::cin >> x >> y >> f) {
		std::string oprs;
		std::cin >> oprs;

		bool lost = false;
		d = (f == 'N' ? 0 :
			f == 'E' ? 1 :
			f == 'S' ? 2 : 3);

		for(auto o: oprs) {
			if(o == 'L') {
				d = (d + 3) % 4;
				continue;
			}
			if(o == 'R') {
				d = (d + 1) % 4;
				continue;
			}
			int nx = x + dx[d], ny = y + dy[d];
			if(0 <= nx && nx <= n && 0 <= ny && ny <= m) {
				x = nx;
				y = ny;
				continue;
			}
			if(scent[x][y]) {
				continue;
			}
			scent[x][y] = true;
			lost = true;
			break;
		}

		std::cout << x << " " << y << " " << FACES[d];
		if(lost) {
			std::cout << " LOST";
		}
		std::cout << "\n";
	}

	return 0;
}
