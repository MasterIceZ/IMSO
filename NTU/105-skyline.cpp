#include <algorithm>
#include <iostream>

const int MxN = 10010;

int mem[MxN];

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int l, h, r;
	while(std::cin >> l >> h >> r) {
		for(int i=l; i<r; ++i) {
			mem[i] = std::max(h, mem[i]);
		}
	}
	int cur = 0;
	bool flag = true;
	for(int i=0; i<MxN; ++i) {
		if(mem[i] != cur) {
			if(!flag) {
				std::cout << " ";
			}
			std::cout << i << " " << mem[i];
			cur = mem[i];
			flag = false;
		}
	}
	std::cout << "\n";
	return 0;
}
