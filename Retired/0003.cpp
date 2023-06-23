#include <cstdio>

int a[110][110], b[110][110];

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	for(int i=1; i<=m; ++i) {
		for(int j=1; j<=n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=1; i<=m; ++i) {
		for(int j=1; j<=n; ++j) {
			scanf("%d", &b[i][j]);
		}
	}
	for(int i=1; i<=m; ++i) {
		for(int j=1; j<=n; ++j) {
			printf("%d ", a[i][j] + b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
