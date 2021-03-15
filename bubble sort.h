#include <stddef.h> 
void SWAP(char* p1, char* p2, int width){
	int i = 1;
	for(i = 1; i <= width; i++){
		char tmp = *p1;
		*p1++ = *p2;
		*p2++ = tmp;
	}
	
}

void bubble_sort(void *base, int n, size_t size, int (*compar)(const void *, const void*)){
	int i = 0, j, tmp;
	for(i = 0; i < n; i++){
		for(j = n-1; j > i; j--){
			tmp = (*compar)((char*)(base + j*size), (char*)(base + (j-1)*size));
			if(tmp == -1){
				SWAP((char*)(base + j*size), (char*)(base + (j-1)*size), size);
			}
		}
	}
}
