#include <iostream> 
#include <time.h> 
using namespace std; 

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

int main(){
	double START,END;
	START = clock();
	FILE *infile;
	infile = fopen("C:\\45.txt", "r");
	int A[350000];
	for(int i = 0; i < 100000; i++){
		fscanf(infile, "%d\n", &A[i]);	
	}
//		for(int i = 0; i < 50000; i++){
//		printf("%d ", A[i]);	
//	}
	insertion_sort(A, 100000);
	
//		for(int i = 0; i < 10000; i++){
//			printf("%d ", A[i]);	
//		}
	END = clock();
	cout << endl << "程式執行所花費：" << (double)clock()/CLOCKS_PER_SEC << " S";
	cout << endl << "進行運算所花費的時間：" << (END - START) / CLOCKS_PER_SEC << " S" << endl;
	fclose(infile);

	return 0;
}

