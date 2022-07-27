#include <iostream>
#include "bitdown.hpp"

using namespace std;

int main(){
	t_bit a;
	cout << a << "\n";
	cout << ~a << "\n";
	a = 1;
	cout << a << "\n";
	cout << ~a << "\n";
	a = 0;
	cout << a << "\n";
	cout << ~a << "\n";

	cout << "----------\n";

	t_bitset<100> b;
	cout << b[0] << "\n";
	b[1] = 20;
	cout << b[1] << "\n";

	return 0;
}
