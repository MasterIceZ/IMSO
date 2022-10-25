#include <bits/stdc++.h>
#include "rescuelib.h"
#ifdef _DEBUG
#include "rescuelib.cpp"
#endif

using namespace std;

int R,C;
vector<pair<int, int>> checker;
vector<int> robots;

inline int get_dist(int a, int b, pair<int, int> c){
	return abs(a - c.first) + abs(b - c.second);
}

inline bool check(int i, int j){
	bool ok = true;
	for(int x=0; x<4; ++x){
		if(robots[x] == -1){
			continue;
		}
		ok &= (get_dist(i, j, checker[x]) == robots[x]);
	}
	return ok;
}

int main()
{
    get_size(R,C);

	checker.emplace_back(1, 1);
	checker.emplace_back(1, C);
	checker.emplace_back(R, 1);
	checker.emplace_back(R, C);

    robots = {drop_robot(1, 1), drop_robot(1, C), drop_robot(R, 1), drop_robot(R, C)};

	vector<pair<int, int>> possible;
	for(int i=1; i<=R; ++i){
		for(int j=1; j<=C; ++j){
			if(check(i, j)){
				possible.emplace_back(i, j);
			}
		}
	}
	for(auto x: possible){
		cout << "(" << x.first << ", " << x.second << ")\n";
	}
//	answer(1,1);
    return 0;
}
