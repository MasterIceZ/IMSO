#include<bits/stdc++.h>
#include "combo.h"

using namespace std;

std::string guess_sequence(int n){
	string s, current = "0";
	int res = 0;
	if(press("AB")){
		if(press("A")){
			current.back() = 'A';
		}
		else{
			current.back() = 'B';
		}
	}
}
