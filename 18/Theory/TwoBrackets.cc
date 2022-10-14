#include <bits/stdc++.h>
using namespace std;

char s[200020];

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf(" %s", s + 1);
		int len = strlen(s + 1), cnt = 0, a = 0, b = 0;
		for(int i=1; i<=len; ++i){
			if(s[i] == '('){
				a++;
			}
			else if(s[i] == ')'){
				if(a >= 1){
					cnt++;
					a--;
				}
			}
			else if(s[i] == '['){
				b++;
			}
			else{
				if(b >= 1){
					cnt++;
					b--;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
