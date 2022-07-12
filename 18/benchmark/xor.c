#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int n = atoi(argv[1]), m = atoi(argv[2]);
	if(n ^ m){
		printf("NOT EQUAL");
	}
	else{
		printf("EQUAL");
	}
	return 0;
}
