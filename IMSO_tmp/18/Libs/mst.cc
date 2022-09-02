class kruskal{
private:
	struct Edge{
		size_t u, v;
		long long w;
		bool operator < (const Edge & o) const {
			return w < o.w;
		}
		Edge(size_t _u, size_t _v, long long _w): u(_u), v(_v), w(_w) {}
	};
	vector<size_t> parent;
	vector<Edge> edges;
	int find_root(size_t u){
		if(u == parent[u]){
			return u;
		}
		return parent[u] = find_root(parent[u]);
	}
public:
	void add_edge(int u, int v, long long w){
		edges.emplace_back(u, v, w);
	}
	long long get_spanning_tree(){
		sort(edges.begin(), edges.end());
		long long sum = 0ll;
		for(auto x: edges){
			int ru = find_root(x.u), rv = find_root(x.v);
			if(ru == rv){
				continue;
			}
			parent[ru] = rv;
			sum += x.w;
		}
		return sum;
	}
	kruskal(size_t n){
		parent.resize(n + 16);
		iota(parent.begin() + 1, parent.begin() + n + 1, 1);
	}
};

template<const size_t S>
class prim{
private:
	struct Node{
		size_t v;
		long long w;
		bool operator < (const Node& o) const {
			return w > o.w;
		}
		Node(size_t _v, long long _w): v(_v), w(_w) {}
	};
	array<vector<pair<int, long long>>, S + 16> adj;
	priority_queue<Node> pq;
	bitset<S + 16> visited;
	void add_edge(size_t u, long long w){
		adj[u].emplace_back(w);
	}
public:
	void add_edge(size_t u, size_t v, long long w){
		add_edge(u, w); add_edge(v, w);
	}
	long long get_spanning_tree(){
		pq.emplace(1, 0);
		long long sum = 0;
		while(!pq.empty()){
			Node now = pq.top(); pq.pop();
			if(visited[now.v]){
				continue;
			}
			visited[now.v] = true;
			sum += now.w;
			for(auto x: adj[now.v]){
				if(visited[x.first]){
					continue;
				}
				pq.emplace(x.first, x.second);
			}
		}
		return sum;
	}
};
