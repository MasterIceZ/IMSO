#ifndef __IMP_FWT__
#define __IMP_FWT__

#include <vector>

template<class T> 
class fenwick_tree{
private:
	std::vector<T> ft;
	size_t n;
	int min(int a, int b){
		return (a < b ? a: b);
	}
public:
	fenwick_tree(size_t N){
		n = N;
		ft.resize(1024 + N);
	}
	inline void update(size_t idx, T value){
		for(; idx<=n; idx+=idx&-idx){
			ft[idx] += value;
		}
	}
	inline T read(size_t idx){
		T now = 0;
		for(; idx; idx-=idx&-idx){
			now += ft[idx];
		}
		return now;
	}
	inline void build(std::vector<int> v){
		for(int i=0; i<=min(n, (int) v.size() - 1); ++i){
			ft[i] += v[i];
			if(i + (i & -i) <= min(n, (int) v.size() - 1)){
				ft[i + (i & -i)] += ft[i];
			}
		}
	}
};

#endif
