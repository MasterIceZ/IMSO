// persistent DSU
int parent[MxN], last_change[MxN], sz[MxN];

int find_root(int u, int ver) {
	if(parent[u] == u || last_change[u] > ver) {
		return u;
	}
	return find_root(parent[u], ver);
}

void unite(int u, int v, int ver) {
	int ru = find_root(u, ver);
	int rv = find_root(v, ver);
	if(ru == rv) {
		return ;
	}
	if(sz[ru] > sz[rv]) {
		swap(ru, rv);
	}
	sz[rv] += sz[ru];
	parent[ru] = rv;
	last_change[ru] = ver;
}

void init(int n) {
	for(int i=1; i<=n; ++i) {
		parent[i] = i;
		sz[i] = 1;
		last_change[i] = 0;
	}
}
