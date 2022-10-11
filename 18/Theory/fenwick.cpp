#include <cstdlib>
#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class fenwick_tree{
protected:
	const unsigned int offset = (1 << 10);
private:
	unsigned int sz;
	T* tree;
public:
	fenwick_tree(unsigned int _sz):
		sz(_sz + offset){
		tree = (T *) calloc(sz, sizeof(T));
	}
};

int main(){

	return 0;
}
