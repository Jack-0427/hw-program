#include <iostream> 
#include <time.h> 
#include <stdlib.h>

using namespace std; 

int compare(const void* a,const void* b){
  return (*(int*)a - *(int*)b);
}

int compareD(const void* a,const void* b){
  double ret = *(double*)a - *(double*)b;
  if(ret > 0){
    return 1;
  }
  else if(ret < 0){
    return -1;
  }
  return 0;
}

int main(){
	double START,END;
	START = clock();
	FILE *infile;
	infile = fopen("C:\\45.txt", "r");
	char C[100000];
	int A[100000];
	long long int L[100000];
	double D[100000];
	for(int i = 0; i < 10000; i++){
		fscanf(infile, "%d\n", &A[i]);	
	}
//	for(int i = 0; i < 100000; i++){
//		fscanf(infile, "%lf\n", &D[i]);	
//	}
//	qsort(D, 10000, sizeof(D[0]), compareD);
	qsort(A, 10000, sizeof(A[0]), compare);
//	for(int i = 0; i < 100000; i++){
//		printf("%lf %d\n", D[i], i);
//	}
	END = clock();
	cout << endl << "程式執行所花費：" << (double)clock()/CLOCKS_PER_SEC << " S";
	cout << endl << "進行運算所花費的時間：" << (END - START) / CLOCKS_PER_SEC << " S" << endl;
	fclose(infile);

	return 0;
}
