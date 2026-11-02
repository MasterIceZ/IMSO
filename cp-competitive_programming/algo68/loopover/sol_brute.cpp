#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

const int MxN = 4;

int n;

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

bool linear_seen(const std::vector<std::string>& visited, const std::string& state) {
	for(const std::string &x: visited) {
		if(x == state) {
			return true;
		}
	}
	return false;
}

int main() {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	std::cin >> n;
	std::string starting = "", target = "";
	for(int i=0, x; i<n*n; ++i) {
		std::cin >> x;
		starting += (char)(x - 1);
		target += (char)i;
	}

	std::vector<std::string> visited;
	std::unordered_map<std::string, std::pair<std::string, std::string>> backtrack;
	std::queue<std::string> q;

	q.push(starting);
	visited.push_back(starting);

	while(!q.empty()) {
		std::string cur = q.front();
		q.pop();
		if(cur == target) break;
		for(int t=0; t<2; ++t) {
			for(int i=0; i<n; ++i) {
				for(int d=0; d<2; ++d) {
					std::string nb = do_move(cur, t, i, d);
					if(linear_seen(visited, nb)) continue;
					visited.push_back(nb);
					std::string move_str = std::to_string(i + 1);
					if(t == 0) move_str += (d == 0 ? "L" : "R");
					else       move_str += (d == 0 ? "U" : "D");
					backtrack[nb] = {cur, move_str};
					q.push(nb);
				}
			}
		}
	}

	std::stack<std::string> st;
	std::string cur = target;
	while(cur != starting) {
		st.push(backtrack[cur].second);
		cur = backtrack[cur].first;
	}
	std::cout << st.size() << "\n";
	while(!st.empty()) {
		std::cout << st.top() << "\n";
		st.pop();
	}
	return 0;
}
