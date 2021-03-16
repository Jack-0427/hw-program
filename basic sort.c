#include <stdio.h>

void insertion_sort(int A[], int n){
	int i = 0, j, tmp;
	for(i = 0; i < n; i++){
		j = i;
		while(A[j] < A[j-1] && j > 0){
			tmp = A[j];
			A[j] = A[j-1];
			A[j-1] = tmp;
			j--;
		}
	}
}

void bubble_sort(int A[], int n){
	int i = 0, j, tmp;
	for(i = 0; i < n; i++){
		for(j = n-1; j > i; j--){
			if(A[j] < A[j-1]){
				tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
			}
		}
	}
}

void selection_sort(int A[], int n){
	int i = 0, min, j, tmp;
	for(i = 0; i < n; i++){
		min = i;
		for(j = i; j < n; j++){
			if(A[j] < A[min])
				min = j;
		}
		tmp = A[i];
		A[i] = A[min];
		A[min] = tmp;
	}
}
int main(){
	int i = 0;
	int A[10] = {25, 37, 41, 15, 28, 24, 3, 8, 6, 0};
	insertion_sort(A, 10);
	for(i = 0; i < 10; i++){
		printf("%d ",A[i]);
	}
} 
