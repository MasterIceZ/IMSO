class disjoint_set{
private:
	size_t *parent, *sz;
public:
	inline size_t find_root(size_t u){
		while(parent[u] != u){
			u = parent[u];
		}
		return u;
	}	
	inline size_t unite(size_t u, size_t v){
		size_t ru = find_root(u), rv = find_root(v);
		if(sz[ru] > sz[rv]){
			sz[ru] = sz[ru] + sz[rv];
			parent[rv] = ru;
			return ru;
		}
		sz[rv] = sz[ru] + sz[rv];
		parent[ru] = rv;
		return rv;
	}
	size_t operator [] (const size_t idx){
		return find_root(idx);
	}
	disjoint_set(size_t n){
		parent = (size_t *) calloc(n + 16, sizeof(size_t));
		sz = (size_t *) calloc(n + 16, sizeof(size_t));
		for(int i=1; i<=n; ++i){
			parent[i] = i;
			sz[i] = 1;
		}
	}
};
