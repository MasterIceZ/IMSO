#include "stack.h"
#include "student.h"
#include <iostream>

using std::cin;
using std::cout;

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	CP::stack<int> stk;
	int M;

	int dataType;
	int query = 0;
	std::string type;
	while(true) {
		query++;
		cin >> type;
		if(type=="si") {
			cout << stk.size() << '\n';
		}
		else if(type=="pu") {
			cin >> M;
			stk.push(M);
		}
		else if(type=="po") {
			stk.pop();
		}
		else if(type=="to") {
			cout << stk.top() << '\n';
		}
		else if(type=="to") {
			cout << stk.top() << '\n';
		}
		else if(type=="di") {
			stk.print_value();
		}
		else if(type=="q") {
			break;
		}
	}
}