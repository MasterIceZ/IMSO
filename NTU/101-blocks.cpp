#include <iostream>
#include <string>
#include <vector>

const int MxN = 33;

std::vector<int> stk[MxN];
int pos[MxN];

inline int get_pos(int x) {
	for(int i=0; i<(int) stk[pos[x]].size(); ++i) {
		if(stk[pos[x]][i] == x) {
			return i;
		}
	}
	return -1;
}

inline void move_back(int x) {
	int p = get_pos(x), q = pos[x];
	for(int i=p+1; i<(int) stk[q].size(); ++i) {
		int t = stk[q][i];
		stk[t].emplace_back(t);
		pos[t] = t;
	}
	stk[q].resize(p + 1);
}

inline void move(int a, int b) {
	int pos_a = pos[a], pos_b = pos[b], p = get_pos(a);
	for(int i=p; i<(int) stk[pos_a].size(); ++i) {
		int t = stk[pos_a][i];
		stk[pos_b].emplace_back(t);
		pos[t] = pos_b;
	}
	stk[pos_a].resize(p);
}


int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for(int i=0; i<n; ++i) {
		stk[i].emplace_back(i);
		pos[i] = i;
	}
	while(1) {
		std::string opr;
		std::cin >> opr;
		if(opr == "quit") {
			break;
		}
		int a, b;
		std::string mode;
		std::cin >> a >> mode >> b;
		
		if(a == b || pos[a] == pos[b]) {
			continue;
		}

		if(opr == "move") {
			move_back(a);
		}
		if(mode == "onto") {
			move_back(b);
		}
		move(a, b);
	}

	for(int i=0; i<n; ++i) {
		std::cout << i << ":";
		for(auto x: stk[i]) {
			std::cout << " " << x;
		}
		std::cout << "\n";
	}

	return 0;
}
