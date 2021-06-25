#include <stdlib.h>
#include <string.h>
#include <iostream> 
#include <stdio.h>
#include <time.h>
#include <Windows.h>
using namespace std;
int A[100000];
double D[100000];

void swap(int* p, int* q){
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

void quick_decreasing(int A[], int left, int right){
	int i, j, index, temp;
	if(left < right){
		i = left;
		j = right;
		index = left;
		while(i < j){
			while(A[i] >= A[index] && i < right)	
				i++;
			while(A[j] < A[index])	
				j--;
			if(i < j){
				A[i] = A[i] + A[j];
				A[j] = A[i] - A[j];
				A[i] = A[i] - A[j];
			}
		}
		temp = A[j];
		A[j] = A[index];
		A[index] = temp;
		quick_decreasing(A, left, j-1);
		quick_decreasing(A, j+1, right);	
	}
}

void quick_increasing(int A[], int left, int right){
	int i, j, index, temp;
	if(left < right){
		i = left;
		j = right;
		index = left;
		while(i < j){
			while(A[i] <= A[index] && i < right)	
				i++;
			while(A[j] > A[index])	
				j--;
			if(i < j){
				A[i] = A[i] + A[j];
				A[j] = A[i] - A[j];
				A[i] = A[i] - A[j];
			}
		}
		temp = A[j];
		A[j] = A[index];
		A[index] = temp;
		quick_increasing(A, left, j-1);
		quick_increasing(A, j+1, right);	
	}
}

int main(){
	FILE *outfile;
	srand((unsigned)time(NULL));
	double START,END;
	int i = 0, d;
	int m = 100000 / 40;
	int v1, v2;
	outfile = fopen("C:\\45.txt", "w");
	for(i = 0; i < 100000; i++){
		A[i] = rand() % 10000;		
	}
//	for(int i = 0; i < 100000; i++){
//		D[i] = (double) rand() / (RAND_MAX + 1.0);
//	}

	
//	quick_decreasing(A, 0, 99999);
//	quick_increasing(A, 0, 99999);
//	for(int i = 0; i < m; i++){
//		v1 = rand() % 50000;
//		v2 = rand() % 50000;
//		swap(A+v1, A+100000-v2);
//		swap(A+30000+v1, A+70000-v2);
//	}

//	for(i = 0; i < 100000; i++){
//		fprintf(outfile, "%f\n", D[i]);
//		printf("%f ", D[i]);
//	}
	for(i = 0; i < 100000; i++){
		fprintf(outfile, "%d\n", A[i]);
		printf("%d ", A[i]);
	}
	fclose(outfile);

	return 0;
} 
