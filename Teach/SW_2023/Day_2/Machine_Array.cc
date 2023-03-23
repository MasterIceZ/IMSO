#include <bits/stdc++.h>
using namespace std;

const int MxN = 300030;
int a[MxN * 2], size = 0;

void insert_heap(int value){
	a[++size] = value;
	int u = size;
	while(u != 1 && a[u] > a[u / 2]){
		swap(a[u], a[u / 2]);
		u = u / 2;
	}
}

int extract_max(){
	if(size == 0){
		return -1;
	}
	int response = a[1];
	swap(a[1], a[size]);
	a[size] = 0;
	size--;
	int u = 1;
	while(u <= size){
		int max_child = max(a[u * 2], a[u * 2 + 1]);
		if(a[u] > max_child){
			break;
		}
		if(a[u * 2] > a[u * 2 + 1]){
			swap(a[u], a[2 * u]);
			u = 2 * u;
		}
		else{
			swap(a[u], a[2 * u + 1]);
			u = 2 * u + 1;
		}
	}
	return response;
}

int main(){
	int n, value;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		char opr;
		scanf(" %c", &opr);
		if(opr == 'P'){
			scanf("%d", &value);
			insert_heap(value);
		}
		else{
			printf("%d\n", extract_max());
		}
	}
	return 0;
}
