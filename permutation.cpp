#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void swap(char* a, char* b){
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void output(char A[], int n){
	int i = 0;
	for(i = 0; i < n; i++){
		printf("%c ", A[i]);
	}
	printf("\n");
}

void generate(char A[], int n){
	int i;
	static int m = n;
	if(n == 1){
		output(A, m);
	}
	else{
		generate(A, n-1);
		for(i = 0; i < n-1; i++){
			if(n % 2 == 0){
				swap(&A[i], &A[n-1]);
			}
			else{
				swap(&A[0], &A[n-1]);
			}
			generate(A, n-1);
		}
	}
}

int get(char* p, char* q){
	int i = 0;
	while(*p != '\0'){
		if(*p != ' '){
			*q++ = *p;
			i++;
		}
		p++;
	}
	*q = '\0';
	return i;
}

int main(){
	int a;
	char data[300];
	char receive[300];
	gets(data);  
	get(data, receive);
	printf("\n");
	generate(receive, get(data, receive));
	
	return 0;
}
