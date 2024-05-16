#include <bits/stdc++.h>

using namespace std;

inline int query(int a, int b, int c) {
	cout << a << " " << b << " " << c << endl;
	int res;
	cin >> res;
	return res;
}

inline void print(int x, int y, int z) {
	cout << x << " " << y << " " << z << endl;
	exit(0);
}

signed main(int argc, char *argv[]) {
	int x = query(1, 0, 0);
	int y = query(0, 1, 0);
	int z = query(0, 0, 1);
	int xyz = query(1, 1, 1);
	int x2y3z = query(1, 2, 3);

	if(x + y + z == xyz) {
		print(x, y, z);
	}
	if(x + 2 * y + 3 * z == x2y3z) {
		print(x, y, z);
	}

	// x lie
	int cur_x = xyz - y - z;
	if(cur_x + 2 * y + 3 * z == x2y3z) {
		print(cur_x, y, z);
	}

	// y lie
	int cur_y = xyz - x - z;
	if(x + 2 * cur_y + 3 * z == x2y3z) {
		print(x, cur_y, z);
	}

	// z lie
	int cur_z = xyz - x - y;
	if(x + 2 * y + 3 * cur_z == x2y3z) {
		print(x, y, cur_z);
	}
	return 0;
}
