int construct_size(int u, int p){
	subtree_size[u] = 1;
	for(auto v: adj[u]){
		if(v == p){
			continue;
		}
		subtree_size[u] = subtree_size[u] + construct_size(v, u);
	}
}

int get_centroid(int u, int p){
	for(auto v: adj[u]){
		if(v == p){
			continue;
		}
		if(subtree_size[u] * 2 > n){
			return get_centroid(v, u);
		}
	}
	return u;
}
