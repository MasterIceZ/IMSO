#ifndef __CP_COMPRESS__
#define __CP_COMPRESS__

#include <vector>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

class compressor_precompute{
private:
	std::vector<int> c;
public:
	size_t get_value(int v){
		return std::upper_bound(c.begin(), c.end(), v) - c.begin();
	}
	compressor_precompute(std::vector<int> x){
		c = x;
		std::sort(c.begin(), c.end());
		c.resize(std::unique(c.begin(), c.end()) - c.begin());
	}
};

class compressor_set{
private:
	__gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> c; 
public:
	size_t get_value(int v){
		return 1 + c.order_of_key(v);
	}
	void add_value(int v){
		c.insert(v);
	}
	compressor_set(std::vector<int> x){
		for(auto _: x){
			c.insert(_);
		}
	}
	compressor_set() {}
};

#endif
