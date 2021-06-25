#include<stdio.h> 
void Merge(Node* arr[], int l, int m, int r){
	Node* left[m-l+1];
	Node* right[r-m];
	int i, j, k = l;
	for (i = 0; i < m-l+1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < r-m; j++)
        right[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	while((i <= m-l) && (j <= r-m-1)){
		if(left[i]->top < right[j]->top){
			arr[k++] = left[i++];
		}
		else if(left[i]->top == right[j]->top){
			if(left[i]->left > right[j]->right){
				arr[k++] = left[i++];
			}
			else{
				arr[k++] = right[j++];
			}
		}
		else{
			arr[k++] = right[j++];
		}
	}
	while (i <= m-l) 
		arr[k++] = left[i++];
	
    while (j <= r-m-1) 
		arr[k++] = right[j++];
}

void MergeSort(Node* arr[], int l, int r){
	int m;
	if(r > l){
    	m = (l + r) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m+1, r);
    	Merge(arr, l, m, r);
	}
}

int main(){
	
}

