#include <stdio.h>
#include <stdlib.h>
#define QUEEN 8

int board[QUEEN][QUEEN] = {0};
int state = 1;
void set(int p[][QUEEN], int i, int j){
	p[i][j] = 1;
	int ti = i;
	int tj = j;
	for(int t = i; t < QUEEN; t++){
		if(p[t][j] != 1){
			p[t][j]--; // 可能重複不行 
		}	
	}
	while(i < QUEEN-1 && j < QUEEN-1){
		p[++i][++j]--;
	}
	while(ti < QUEEN-1 && tj > 0){
		p[++ti][--tj]--;
	}
}

void reset(int p[][QUEEN], int i, int j){
	p[i][j] = 0;
	int ti = i;
	int tj = j;
	for(int t = i; t < QUEEN; t++){
			p[t][j]++; // 可能重複不行 
	}
	p[i][j] = 0;
	while(i < QUEEN-1 && j < QUEEN-1){
		p[++i][++j]++;
	}
	while(ti < QUEEN-1 && tj > 0){
		p[++ti][--tj]++;
	}
}

void print(int p[][QUEEN]){
	for(int i = 0; i < QUEEN; i++){
		for(int j = 0; j < QUEEN; j++){
			if(p[i][j] == 1){
				printf("Q ");
			}
			else{
				printf("_ ");
			}
		}
		printf("\n");
	}
}

void recur(int p[][QUEEN], int i){
	if(i == QUEEN){
		print(p);
		printf("\n");
		state = 0;
		return;
	}
	for(int k = 0; k < QUEEN; k++){
		if(state == 0){
			if(p[i+1][QUEEN-1] == 1){
				reset(p, i+1, QUEEN-1);
			}
			reset(p, i, k-1);
			state = 1;
		}
		if(p[i][k] == 0){		
			set(p, i, k);
			recur(p, i+1);
		}
	}
	state = 0;
}

int main(){
	recur(board, 0);
	return 0;
} 
