#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int way[300];
void make(int now, int a, int n, int k){
	if(now == k){
		for(int i = 0; i < k; i++){
			printf("%d ", way[i]);
		}
		printf("\n");
	}
	else{
		 for(int b = a; b < n; b++){
             way[now] = b+1;
             make(now+1, b+1, n, k);
         }
	}
}
int main(){
	int n;
 int k;
	scanf("%d %d", &n, &k);
	make(0, 0, n, k);
}
