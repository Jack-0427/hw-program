#include <stddef.h> 
void swap(char* e1, char* e2, int width){
	int i = 0;
	for(i = 1; i <= width; i++){
		char tmp = *e1;
		*e1++ = *e2;
		*e2++ = tmp;
	}
}

void insertion_sort(void *base, int n, size_t size, int (*compar)(const void *, const void*)){
	int i = 0, j, a;
	for(i = 0; i < n; i++){
		j = i;
			a = (*compar)((char*)(base+j*size), (char*)(base+(j-1)*size));
		while(a == -1 && j > 0){
			swap((char*)(base+j*size), (char*)(base+(j-1)*size), size);
			j--;
			a = (*compar)((char*)(base+j*size), (char*)(base+(j-1)*size));
		}
	}
}


