#include <iostream>
#include "graph.hpp"

using namespace std;

int main(){
	graph::weighted_graph<int> g(3);
	g.add_edge(1, 2, 3);
	g.add_edge(2, 3, 1);
	g.add_edge(1, 3, 4);
	for(auto x: g[1]){
		cout << x.first << " " << x.second << "\n";
	}
	
	return 0;
}
