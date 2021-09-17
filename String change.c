#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int black;
	int red;
};
	
typedef struct node Node;

int compare(char p[], char q[], int i){
	int j;
	for(j = 0; j < i; j++){
		if(p[j] != q[i-1-j]){
			return 0;
		}
	}
	return 1;
}

char text[100000];
char garbage[100000];
char split[100000];
int now[128] = {0};
int target[128] = {0};
Node all[100000];

int main(){
	int n, i, j = 0, x = 0, k, f = 0;
	int count = 0, meet = 0, check = 0;
	int black = 0, min;
	int real = 0;
	int p1 = 0;
	int sum1 = 0;
	int sum2 = 0;
	char tmp1[50000];
	char tmp2[50000];
	char final[200000];
	int tag[50000] = {0}, tagging = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%s", text);
		scanf("%s", garbage);
		while(garbage[j] != '\0'){
			if(target[garbage[j]] == 0){
				count++;
			}
			target[garbage[j]]++;
			j++;
		}
		j = 0;
		while(text[j] != '\0'){
			if(meet != count){
				if(target[text[j]] >= 1){
					now[text[j]]++;
				}
				if(now[text[j]] == target[text[j]] && target[text[j]] >= 1){
					meet++;
				}
				j++;		
			}
			else{
				if(now[text[black]] > target[text[black]]){
					now[text[black]]--;
				}
				else if(now[text[black]] == target[text[black]] && target[text[black]] >= 1){
					all[x].black = black;
					all[x].red = j-1;
					now[text[black]]--;
					x++;
					meet--;
				}
				black++;
			}
		}
		while(meet == count){
			if(now[text[black]] > target[text[black]]){
				now[text[black]]--;
			}
			else if(now[text[black]] == target[text[black]] && target[text[black]] >= 1){
				all[x].black = black;
				all[x].red = j-1;
				now[text[black]]--;
				x++;
				meet--;
			}
			black++;
		}
		if(x == 0){
			tagging = 0;
			f = 0;
			while(f < j-1-f){
				sum1 += text[f];
				sum2 += text[j-1-f];
				tmp1[p1] = text[f];
				tmp2[p1] = text[j-1-f];
				p1++;
				if(sum1 == sum2){
					if(compare(tmp1, tmp2, p1) == 1){
						p1 = 0;
						sum1 = 0;
						sum2 = 0;
						tag[tagging++] = f;
					}
				}
				f++;
			}
			for(k = 0; k < j; k++){
				final[real++] = text[k];		
				if(k == tag[check] && check < tagging){
					final[real++] = '|';
					check++; 
				}
				else if(k == j - tag[check-1] - 2 && check > 0){
					final[real++] = '|';
					check--; 
				}
			}
			sum1 = 0;
			sum2 = 0;
			for(k = 0; k < j + 2 * tagging; k++){
				printf("%c", final[k]);
			}
			printf("\n");
		}
		else{
			min = 0;
			for(k = 0; k < x; k++){
				if((all[k].red - all[k].black) < (all[min].red - all[min].black)){
					min = k;
				}
			}
			for(k = 0; k < all[min].black; k++){
				garbage[k] = text[k];
			}
			for(k = all[min].red+1; k < j; k++){
				garbage[k-all[min].red+all[min].black-1] = text[k];
			}
			j = j - all[min].red + all[min].black - 1;
			tagging = 0;
			f = 0;
			while(f < j-1-f){
				sum1 += garbage[f];
				sum2 += garbage[j-1-f];
				tmp1[p1] = garbage[f];
				tmp2[p1] = garbage[j-1-f];
				p1++;
				if(sum1 == sum2){
					if(compare(tmp1, tmp2, p1) == 1){
						p1 = 0;
						sum1 = 0;
						sum2 = 0;
						tag[tagging++] = f;
					}
				}
				f++;
			}
			printf("%d\n", tagging);
			for(k = 0; k < j; k++){
				final[real++] = garbage[k];		
				if(k == tag[check] && check < tagging){
					final[real++] = '|';
					check++; 
				}
				else if(k == j - tag[check-1] - 2 && check > 0){
					final[real++] = '|';
					check--; 
				}
			}
			sum1 = 0;
			sum2 = 0;
			for(k = 0; k < j + 2 * tagging; k++){
				printf("%c", final[k]);
			}
			printf("\n");
		}		
		for(k = 0; k < 127; k++){
			now[k] = 0;
			target[k] = 0;
		}
		count = 0;
		meet = 0;
		black = 0;
		j = 0;
		x = 0;
		real = 0;
	}
//	for(k = 0; k < x; k++){
//		printf("%d %d\n", all[k].black, all[k].red);
//	}
	return 0;
} 

// »Pb08209032 ¨H¥@©ú°Q½× 
