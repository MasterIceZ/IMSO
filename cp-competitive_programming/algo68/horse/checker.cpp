#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
	std::ifstream inf(argv[1]);
	std::ifstream ans(argv[2]);
	std::ifstream ouf(argv[3]);

	int k, n;
	inf >> k >> n;
	
	int lines;
	ouf >> lines;

	return 0;
}
