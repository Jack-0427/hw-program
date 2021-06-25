#include <iostream> 
#include <time.h> 
using namespace std; 

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
	double START,END;
	START = clock();
	FILE *infile;
	infile = fopen("C:\\45.txt", "r");
	int A[300000];
	for(int i = 0; i < 100000; i++){
		fscanf(infile, "%d\n", &A[i]);	
	}
	selection_sort(A, 100000);
//	for(int i = 0; i < 50000; i++){
//		printf("%d ", A[i]);	
//	}
	END = clock();
	cout << endl << "程式執行所花費：" << (double)clock()/CLOCKS_PER_SEC << " S";
	cout << endl << "進行運算所花費的時間：" << (END - START) / CLOCKS_PER_SEC << " S" << endl;
	fclose(infile);

	return 0;
}
