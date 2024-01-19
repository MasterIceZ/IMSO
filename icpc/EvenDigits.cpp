#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	if(n == 1) {
		cout << "0\n";
		return 0;
	}
	n--;
	string answer = "";
	while(n > 0) {
		answer += "02468"[n % 5];
		n /= 5;
	}
	reverse(answer.begin(), answer.end());
	cout << answer << "\n";
	return 0;
}
