#ifndef __CP_TOPDOWN_BITS__
#define __CP_TOPDOWN_BITS__

#include <cstdbool>
#include <array>

class t_bit {
private:
	int value;
public:
	t_bit operator = (const int x){
		value = x;
		return true;
	}
	t_bit operator = (const bool x){
		if(x){
			value = 1;
		}
		else{
			value = 0;
		}
		return true;
	}
	t_bit operator ~ (){
		if(value == -1){
			return -1;
		}
		else{
			return !value;
		}
	}
	t_bit(int x=-1): value(x) {}
	operator int() const {
		return value;
	}
};

#endif
