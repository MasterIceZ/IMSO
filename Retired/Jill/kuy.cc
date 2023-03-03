#include <iostream>
using namespace std;

int main(){
	// int -> integer
	// <data type> <name_1>, <name_2>, ...;
	int jill = 10;
	cout << jill << "\n"; // correct
	cout << "jill\n"; // wrong

	// cin -> input
	int input_1, input_2;
	cin >> input_1 >> input_2;
	cout << "Input #1: " << input_1 << "\n";
	cout << "Input #2: " << input_2 << "\n";

	return 0;
}
