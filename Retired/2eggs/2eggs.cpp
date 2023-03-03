#include "2eggs.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;

int height_threshold(int N, int Q) {
	if(N == 2){
		bool Jill = drop_egg(1, 1);
		if(Jill == true){
			return 1;
		}
		else{
			return 2;
		}
	}
	if(N == 4){
		bool Jill = drop_egg(1, 2);
		if(Jill == true){
			bool Pakpim = drop_egg(2, 1);
			if(Pakpim == true){
				return 1;
			}
			return 2;
		}
		else{
			bool Pakpim = drop_egg(2, 3);
			if(Pakpim == true){
				return 3;
			}
			return 4;
		}
	}
	if(N == 100){
		vector<int> ToroTN = {0, 15, 29, 42, 54, 65, 75, 84, 92, 99};
		for(int PP=1; PP<(int) ToroTN.size(); ++PP){
			bool Jill = drop_egg(1, ToroTN[PP]);
			if(Jill == false){
				continue;
			}
			for(int Pakpim=ToroTN[PP - 1] + 1; Pakpim < ToroTN[PP]; ++Pakpim){
				bool Directory = drop_egg(2, Pakpim);
				if(Directory == false){
					continue;
				}
				return Pakpim;
			}
			return ToroTN[PP];
		}
		return 100;
	}
}
