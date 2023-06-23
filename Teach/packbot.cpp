#include <bits/stdc++.h>
using namespace std ;

stack<int> val;
stack<char> opr;

int calculate_promo(int l, int r) {
	int operation = (opr.top() - '0');
	if(operation == 1) {
		return (l + r) * 104 / 100;
	}
	else if(operation == 2) {
		return (l + r) * 108 / 100;
	}
	return (l + r) * 116 / 100;
}


void process() {
	int r = val.top(); val.pop();
	int l = val.top(); val.pop();
	int new_value = calculate_promo(l, r);
	val.push(new_value);
}

int get_priority(char x) {
	if(isdigit(x)) {
		return -1;
	}
	return x - '0';
}

int main() {
	string s;
	cin >> s;
	for(auto x: s) {
		//cout << "Current : " << x << "\n";
		// check alphabet
		if(isalpha(x)){
			val.push(20);
		}
		else if(x == '[') {
			opr.push(x);
		}
		else if(x == ']') {
			while(opr.top() != '[') {
				process();
			}
			opr.pop(); // pop '[' out
		}
		else {
			//cout << "IN\n";
			while(!opr.empty() && get_priority(opr.top()) >= get_priority(x)) {
				process();
			}
			opr.push(x);
		}
	}
	while(!opr.empty()) {
		process();
	}
	cout << "Answer = " << val.top() << "\n";
	return 0;
}
