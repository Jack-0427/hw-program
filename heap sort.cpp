#include <stdio.h>
#include <malloc.h>

void swap(int* x, int* y){
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

int* heapsort(int* A, int n){
	int* sort = (int*)malloc(sizeof(int)*n);
	int x = 0;
	while(n > 0){
		int i = n-1, min = 0;
		while(i > 0){
			int j = (i-1) / 2;
			if(A[i] < A[j]){
				swap(A+i, A+j);
				j = i;
				while(j*2 < n){
					if((j+1)*2 == n){
						min = j*2+1;
					}
					else if((j+1)*2 < n){
						min = (A[j*2+1] < A[(j+1)*2]) ? j*2+1 : (j+1)*2;
					}
					if(A[j] <= A[min]){
						break;	
					}
					swap(A+j, A+min);
					j = min;
				}
			}
			i--;
		}
		sort[x++] = A[0];
		swap(A, A+n-1);
		n--;
	}
	return sort;
}

int main(){
	int heap[13] = {2, 5, 5, 8, 9, 4, 3, 7, 1, 10, 26, 39, 14};
	int* sort = (int*)malloc(sizeof(int)*13);
	sort = heapsort(heap, 13);
	for(int i = 0; i < 13; i++){
		printf("%d ", sort[i]);
	} 
}
