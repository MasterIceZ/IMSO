#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MxN = 1000010;

bitset<MxN> done;
vector<int> factor[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	for(int i=2; i<MxN; ++i) {
		factor[i].emplace_back(1);
		if(done[i]) {
			continue;
		}
		for(int j=i; j<MxN; j+=i) {
			done[j] = true;
			factor[j].emplace_back(i);
		}
	}
	for(auto x: factor[60]) {
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}
