#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

const int MxN = 4;

struct state_t {
	std::string board;
	int g, f;
	int last_t, last_i, last_d;

	state_t(std::string _board, int _g, int _f, int _last_t, int _last_i, int _last_d):
		board(_board), g(_g), f(_f), last_t(_last_t), last_i(_last_i), last_d(_last_d) {}

	bool operator < (const state_t& o) const {
		if(f != o.f) {
			return f > o.f;
		}
		return g > o.g;
	}
};

int n, a[MxN * MxN], mem[MxN * MxN][MxN * MxN];

int bad_heuristic(const std::string &b) {
	// Deliberately bad: reward already-correct tiles.
	// In a minimization priority queue, this pushes near-goal states to lower priority.
	int h = 0;
	for(int i=0; i<n*n; ++i) {
		h += (b[i] == (char)i ? 5 : 0);
	}
	return h;
}

int bad_cost(const std::string &b, int g) {
	// Deliberately bad best-first cost:
	// f = g + 20 * bad_heuristic
	// This penalizes states that look close to the goal.
	return g + 20 * bad_heuristic(b);
}

std::string do_move(std::string s, int type, int idx, int dir) {
	if(type == 0) {
		int K = idx * n;
		if(dir == 0) {
			char t = s[K];
			for(int i=0; i<n-1; ++i) s[K + i] = s[K + i + 1];
			s[K + n - 1] = t;
		}
		else {
			char t = s[K + n - 1];
			for(int i=n-1; i>0; --i) s[K + i] = s[K + i - 1];
			s[K] = t;
		}
	}
	else {
		if(dir == 0) {
			char t = s[idx];
			for(int i=0; i<n-1; ++i) s[i * n + idx] = s[(i + 1) * n + idx];
			s[(n - 1) * n + idx] = t;
		}
		else {
			char t = s[(n - 1) * n + idx];
			for(int i=n-1; i>0; --i) s[i * n + idx] = s[(i - 1) * n + idx];
			s[idx] = t;
		}
	}
	return s;
}

int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;
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
	pq.emplace(starting, 0, bad_cost(starting, 0), -1, -1, -1);

	while(!pq.empty()) {
		state_t cur = pq.top();
		pq.pop();

		// Delayed duplicate filtering (intentional):
		// many duplicate states stay in the priority queue and waste time.
		if(searched.find(cur.board) != searched.end()) {
			continue;
		}
		searched.emplace(cur.board);

		if(cur.board == target) break;
		for(int t=0; t<2; ++t) {
			for(int i=0; i<n; ++i) {
				for(int d=0; d<2; ++d) {
					std::string new_board = do_move(cur.board, t, i, d);
					std::string move_str = std::to_string(i + 1);
					if(t == 0) move_str += (d == 0 ? "L" : "R");
					else       move_str += (d == 0 ? "U" : "D");

					if(backtrack.find(new_board) == backtrack.end()) {
						backtrack[new_board] = std::make_pair(cur.board, move_str);
					}

					int ng = cur.g + 1;
					pq.emplace(new_board, ng, bad_cost(new_board, ng), t, i, d);
				}
			}
		}
	}

	if(starting != target && backtrack.find(target) == backtrack.end()) {
		// If this intentionally weak search fails to settle the target in time,
		// output an empty plan to keep behaviour defined.
		std::cout << 0 << "\n";
		return 0;
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
