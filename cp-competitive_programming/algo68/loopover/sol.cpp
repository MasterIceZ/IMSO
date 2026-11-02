#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

const int MxN = 4;

struct state_t {
	std::string board;
	int x, y;
	int last_t, last_i, last_d;

	state_t(std::string _board, int _x, int _y, int _last_t, int _last_i, int _last_d):
		board(_board), x(_x), y(_y), last_t(_last_t), last_i(_last_i), last_d(_last_d) {}

	bool operator < (const state_t& o) const {
		if(x + 5 * y != o.x + 5 * o.y) {
			return x + 5 * y > o.x + 5 * o.y;
		}
		return y > o.y;
	}
};

int n, a[MxN * MxN], mem[MxN * MxN][MxN * MxN];

int heuristic(const std::string &b) {
	int h = 0;
	for(int i=0; i<n*n; ++i) {
		h += mem[b[i]][i];
	}
	return h / n;
}

std::string do_move(std::string s, int type, int idx, int dir) {
	if(type == 0) {
		// LR
		int K = idx * n;
		if(dir == 0) {
			// left
			char t = s[K];
			for(int i=0; i<n-1; ++i) {
				s[K + i] = s[K + i + 1];
			}
			s[K + n - 1] = t;
		}
		else {
			// right
			char t = s[K + n - 1];
			for(int i=n-1; i>0; --i) {
				s[K + i] = s[K + i - 1];
			}
			s[K] = t;
		}
	}
	else {
		// UD
		if(dir == 0) {
			// up
			char t = s[idx];
			for(int i=0; i<n-1; ++i) {
				s[i * n + idx] = s[(i + 1) * n + idx];
			}
			s[(n - 1) * n + idx] = t;

		}
		else {
			char t = s[(n - 1) * n + idx];
			for(int i=n-1; i>0; --i) {
				s[i * n + idx]  = s[(i - 1) * n + idx];
			}
			s[idx] = t;
		}
	}
	return s;
}

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	std::cin >> n;
	for(int i=0; i<n*n; ++i) {
		int tr = i / n, tc = i % n;
		for(int j=0; j<n*n; ++j) {
			int cr = j / n, cc = j % n;
			int dr = abs(tr - cr), dc = abs(tc - cc);
			dr = std::min(dr, n - dr);
			dc = std::min(dc, n - dc);
			mem[i][j] = dr + dc;
		}
	}
	std::string starting = "", target = "";
	for(int i=0, x; i<n*n; ++i) {
		std::cin >> x;
		starting += (char) (x - 1);
		target += (char) i;
	}

	std::unordered_set<std::string> searched;
	std::unordered_map<std::string, std::pair<std::string, std::string>> backtrack;
	std::priority_queue<state_t> pq;
	pq.emplace(starting, 0, heuristic(starting), -1, -1, -1);
	searched.emplace(starting);

	while(!pq.empty()) {
		state_t cur = pq.top();
		pq.pop();
		if(cur.board == target) {
			break;
		}
		for(int t=0; t<2; ++t) {
			for(int i=0; i<n; ++i) {
				for(int d=0; d<2; ++d) {
					if(t == cur.last_t && i == cur.last_i && d == 1 - cur.last_d ) {
						continue;
					}
					std::string new_board = do_move(cur.board, t, i, d);
					if(searched.find(new_board) != searched.end()) {
						continue;
					}
					searched.emplace(new_board);
					std::string move_str = std::to_string(i + 1);
					if(t == 0) {
						move_str += (d == 0 ? "L": "R");
					}
					else {
						move_str += (d == 0 ? "U": "D");
					}
					backtrack[new_board] = std::make_pair(cur.board, move_str);
					pq.emplace(new_board, cur.x + 1, heuristic(new_board), t, i, d);
				}
			}
		}
	}

	std::stack<std::string> st;
	std::string cur_board = target;
	while(cur_board != starting) {
		st.emplace(backtrack[cur_board].second);
		cur_board = backtrack[cur_board].first;
	}
	std::cout << st.size() << "\n";
	while(!st.empty()) {
		std::cout << st.top() << "\n";
		st.pop();
	}
	return 0;
}
