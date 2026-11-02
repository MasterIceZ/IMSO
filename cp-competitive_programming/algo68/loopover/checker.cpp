#include <fstream>
#include <iostream>
#include <vector>
#include <string>

inline void correct() {
	std::cout << "1.0\n";
	std::cerr << "translate:correct\n";
	exit(0);
}

inline void wrong() {
	std::cout << "0.0\n";
	std::cerr << "translate:wrong\n";
	exit(0);
}

int main(int argc, char *argv[]) {
	std::ifstream inf(argv[1]);
	std::ifstream ouf(argv[2]);
	std::ifstream ans(argv[3]);

	int n;
	inf >> n;
	std::vector<int> board(n * n);
	for(int i = 0; i < n * n; ++i) {
		inf >> board[i];
		board[i]--; // convert to 0-indexed
	}

	int user_out;
	if(!(ouf >> user_out) || user_out < 0) wrong();

	std::vector<std::string> moves;
	std::string move;
	while(ouf >> move) {
		moves.emplace_back(move);
	}
	if((int)moves.size() < user_out) wrong();
	moves.resize(user_out);

	// Apply each move to the board
	for(const std::string& m : moves) {
		if(m.size() < 2) wrong();
		char dir = m.back();
		int idx;
		try {
			idx = std::stoi(m.substr(0, m.size() - 1)) - 1; // convert to 0-indexed
		} catch(...) {
			wrong();
		}
		if(idx < 0 || idx >= n) wrong();

		if(dir == 'L') {
			// shift row idx left (wraps around)
			int K = idx * n;
			int t = board[K];
			for(int i = 0; i < n - 1; ++i) board[K + i] = board[K + i + 1];
			board[K + n - 1] = t;
		} else if(dir == 'R') {
			// shift row idx right (wraps around)
			int K = idx * n;
			int t = board[K + n - 1];
			for(int i = n - 1; i > 0; --i) board[K + i] = board[K + i - 1];
			board[K] = t;
		} else if(dir == 'U') {
			// shift col idx up (wraps around)
			int t = board[idx];
			for(int i = 0; i < n - 1; ++i) board[i * n + idx] = board[(i + 1) * n + idx];
			board[(n - 1) * n + idx] = t;
		} else if(dir == 'D') {
			// shift col idx down (wraps around)
			int t = board[(n - 1) * n + idx];
			for(int i = n - 1; i > 0; --i) board[i * n + idx] = board[(i - 1) * n + idx];
			board[idx] = t;
		} else {
			wrong();
		}
	}

	// Check board matches target: board[i] == i (0-indexed tiles 0..n²-1)
	for(int i = 0; i < n * n; ++i) {
		if(board[i] != i) wrong();
	}

	correct();
	return 0;
}
