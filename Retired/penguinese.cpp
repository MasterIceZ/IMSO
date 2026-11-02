#include <iostream>
#include <iterator>
#include <list>
#include <string>

int main(int argc, char *argv[]) {
	int n;
	std::cin >> n;
	std::list<std::string> ls;
	for(int i=1; i<=n; ++i) {
		std::string s;
		std::cin >> s;
		ls.emplace_back(s);
	}
	std::list<std::string>::iterator it = ls.begin();
	for(int _=1; _<=2*n-1; ++_) {
		std::string o;
		std::cin >> o;
		if(o == "SHIFT") {
			it++;
		}
		else if(o == "RIGHT") {
			ls.erase(std::prev(it, 2));
		}
		else if(o == "LEFT") {
			it = ls.erase(std::prev(it, 1));
		}
	}
	std::cout << *ls.begin() << "\n";
	return 0;
}
