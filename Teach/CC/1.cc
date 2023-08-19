#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	while(cin >> s) {
		bool have_small = false;
		bool have_capital = false;
		bool have_special = false;
		bool have_number = false;
		for(auto x: s) {
			if('a' <= x && x <= 'z') {
				have_small = true;
			}
			else if('A' <= x && x <= 'Z') {
				have_capital = true;
			}
			else if('0' <= x && x <= '9') {
				have_number = true;
			}
			else {
				have_special = true;
			}
		}
		if(s.size() >= 12 && have_small && have_capital && have_number && have_special) {
			cout << "strong";
		}
		else if(s.size() >= 8 && have_small && have_capital && have_number) {
			cout << "weak";
		}
		else {
			cout << "invalid";
		}
		cout << "\n";
	}
	return 0;
}
