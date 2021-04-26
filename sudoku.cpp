#include <stdio.h>
#include <stdlib.h>

int back[10] = {0};
int first[10] = {0};
int last[10] = {0};
int board[9][9];
int state[9][9];
int j;
int trace = 0;

void print(int p[][9]){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}

int check(int p[][9], int i, int j, int l){
	for(int ti = 0; ti < 9; ti++){
		if(p[ti][j] == l){
			return 0;
		}
	}
	
	for(int tj = 0; tj < 9; tj++){
		if(p[i][tj] == l){
			return 0;
		}
	}
	int ti = i / 3;
	int tj = j / 3;
	for(int tti = (3 * ti); tti <= (3 * ti) + 2; tti++){
		for(int ttj = (3 * tj); ttj <= (3 * tj) + 2; ttj++){
			if(p[tti][ttj] == l){
				return 0;
			}
		}
	}
	return 1;
}

void setfirst(int A[]){
	int j;
	for(int i = 0; i < 9; i++){
		j = 0;
		while(state[i][j] > 0){
			j++;
		}
		A[i] = j;
	}
}

void setlast(int A[]){
	int j;
	for(int i = 0; i < 9; i++){
		j = 8;
		while(state[i][j] > 0){
			j--;
		}
		A[i] = j;
	}
}
int get(int p[][9], int i, int j){
	int k = p[i][j] + 1;
	for(int l = k; l <= 9; l++){
		if(check(p, i, j, l) == 1){
			return l;
		}
	}
	return -1;
}

void recur(int p[][9], int i){
	if(i == 9 && trace == 0){
		print(p);
		printf("\n");
		trace = 1;
	}
	
	else if(back[i] == 0){
		j = first[i];
	}
	else if(back[i] == 1){
		j = last[i];
	}
	for(int j1 = j; j1 <= last[i]; j1++){
		back[i] = 0;
		if(state[i][j1] == 0){
			if(get(p, i, j1) == -1){
				p[i][j1] = 0;
				if(j1 == 0){
					back[i-1] = 1;
					recur(p, i-1);
				}
				j1--;
				while(state[i][j1] > 0){
					if(j1 == 0){
						back[i-1] = 1;
						recur(p, i-1);
					}
					j1--;
				}
				j1--;
			}
			else{
				p[i][j1] = get(p, i, j1);
			}
		}
	}
	recur(p, i+1);
}
	
int main(){
	FILE *infile;
	infile = fopen("C:\\sudoku.csv", "r");
	int i = 0;
	char c;
	
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			fscanf(infile, "%c", &c);
			if(c == ',' || c == '\n'){
				j--;
			}
			else{
				if(0 <= c && c <= '9'){
					board[i][j] = c - '0';
					state[i][j] = c - '0';
				}
				else{
					board[i][j] = 0;
					state[i][j] = 0;
				}	
			}
		}
	}
	setfirst(first);
	setlast(last);
	recur(board, 0);
	
	return 0;
} 
