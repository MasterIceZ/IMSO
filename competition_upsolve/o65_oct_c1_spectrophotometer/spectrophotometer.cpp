#include "spectrophotometer.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

// call_swap(a, b)
// returns true if a == b

int b[3];

void sort_lasers(int N) {
	b[0] = b[1] = b[2] = -1;
	for(int i=0; i<3*N; ++i) {
		int j=2, c = i;
		while(j > 0) {
			if(b[j] == -1) {
				b[j] = c;
				break;
			}
			if(call_swap(b[j], c)) {
				break;
			}
			c = b[j--]++;
		}
	}
}
