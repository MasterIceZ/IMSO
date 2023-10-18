#include <stdio.h>

int main() {
	int m, x, minn = 2e9 + 10, maxx = -2e9 - 10;
	scanf("%d", &m);
	while(m--) {
		scanf("%d", &x);
		if(maxx < x) {
			maxx = x;
		}
		if(minn > x) {
			minn = x;
		}
	}
	printf("%d\n%d\n", minn, maxx);
	return 0;
}
