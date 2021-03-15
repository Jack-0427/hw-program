#include <stddef.h> 
void swap(char* e1, char* e2, int width){
	int i = 0;
	for(i = 1; i <= width; i++){
		char tmp = *e1;
		*e1++ = *e2;
		*e2++ = tmp;
	}
}

void selection_sort(void *base, int n, size_t size, int (*compar)(const void *, const void*)){
	int i = 0, min, j, a, k;
	for(i = 0; i < n; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			a = (*compar)((char*)(base+j*size), (char*)(base+min*size));
			if(a == -1)
				min = j;
		}
		swap((char*)(base+i*size), (char*)(base+min*size), size);
	}
}


