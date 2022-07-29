#include <iostream>
#include "compress.hpp"

using namespace std;

int main(){
	compressor_precompute cp({1, 5, 1, 3, 2, 3, 5, 1});
	// 1 2 3 5
	cout << cp.get_value(5) << "\n";
	compressor_set cp2;
	cp2.add_value(1);
	cp2.add_value(5);
	cp2.add_value(1);
	cp2.add_value(3);
	cp2.add_value(2);
	cp2.add_value(3);
	cp2.add_value(5);
	cp2.add_value(1);
	cout << cp2.get_value(1) << "\n";
	return 0;
}
