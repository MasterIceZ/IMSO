// graph lib
// for competitive programming :D

#ifndef __CP_GRAPH__
#define __CP_GRAPH__

#include <vector>
#include <array>
#include <cstdbool>

namespace graph{

template<typename T> 
class weighted_graph{
protected:
	const size_t offset = 16;
private:
	size_t n;
	std::vector<std::vector<std::pair<int, T>>> adj;
public:
	void add_edge(size_t a, size_t b, T c){
		adj[a].emplace_back(b, c);
	}
	std::vector<std::pair<int, T>> &operator [](size_t a) {
		return this->adj[a];
	}
	weighted_graph(size_t sz){
		n = sz + offset;
		adj.resize(n);
	}
};

class graph{
protected:
	const size_t offset = 16;
private:
	size_t n;
	std::vector<std::vector<int>> adj;
public:
	void add_edge(size_t a, size_t b){
		adj[a].emplace_back(b);
	}
	std::vector<int> &operator [](size_t a) {
		return this->adj[a];
	}
	graph(size_t sz){
		n = sz + offset;
		adj.resize(n);
	}
};
}
#endif
