#include <bits/stdc++.h>
using namespace std;

const int MxN = 300030;
int a[MxN * 2], last_idx = 0;

void heapify(){
	for(int i=last_idx/2; i>=1; --i){
		int now = i;
		while(a[now] < max(a[now * 2], a[now * 2 + 1])){
			if(a[now * 2] > a[now * 2 + 1]){
				swap(a[now], a[now * 2]);
				now = now * 2;
			}
			else{
				swap(a[now], a[now * 2 + 1]);
				now = now * 2 + 1;
			}
		}
	}
}

int extract_max(){
	if(last_idx == 0){
		return -1;
	}
	int response = a[1];
	swap(a[1], a[last_idx]);
	a[last_idx--] = -1;
	int current = 1;
	while(current <= last_idx){
		int max_child = max(a[current * 2], a[current * 2 + 1]);
		if(a[current] > max_child){
			break;
		}
		if(a[current * 2] > a[current * 2 + 1]){
			swap(a[current], a[current * 2]);
			current = current * 2;
		}
		else{
			swap(a[current], a[current * 2 + 1]);
			current = current * 2 + 1;
		}
	}
	return response;
}

void insert_heap(int value){
	a[++last_idx] = value;
	int current = last_idx;
	while(current != 1 && a[current] > a[current / 2]){
		swap(a[current], a[current / 2]);
		current = current / 2;
	}
}

void show_heap(){
	printf("Current Heap : ");
	for(int i=1; i<=last_idx; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(){
	int n, value, q;
	scanf("%d %d", &n, &q);
	memset(a, -1, sizeof a);
	for(int i=1; i<=n; ++i){
		scanf("%d", &a[i]);
		last_idx++;
	}
	show_heap();
	heapify();
	show_heap();
	while(q--){
		char opr;
		scanf(" %c", &opr);
		if(opr == 'P'){
			scanf("%d", &value);
			insert_heap(value);
		}
		else{
			printf("%d\n", extract_max());
		}
		show_heap();
	}
	return 0;
}
