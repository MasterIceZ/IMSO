#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	if(a.size() != b.size()) {
		cout << "Incomplete answer";
		return 0;
	}
	int sz = a.size(); // size_t -> usigned long long
	a = " " + a; // "AAAAA" -> " AAAAA"
	b = " " + b;
	int count_correct = 0;
	for(int i=1; i<=sz; ++i) {
		if(a[i] == b[i]) {
			count_correct += 1;
		}	
	}
	cout << count_correct << "\n";
	return 0;
}
