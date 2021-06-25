#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct node{
	int data;
	struct node* next;
};

typedef struct node Node;

Node* TOP[1000] = {NULL};

Node* add(Node* top, int n){
	Node* newer = (Node*)malloc(sizeof(Node));
	newer->next = top;
	newer->data = n;
	top = newer;
	return top;
}

Node* deleted(Node* top){
	if(!top){
		return NULL;
	}
	Node* tmp = top;
	top = top->next;
	free(tmp);
	tmp = NULL;
	return top;
}

Node* migrate(Node* close, Node* open){
	if(close != NULL){
		Node* p = close;
		Node* q = close;
		if(!close->next){
			if(open == NULL){
				return close;
			}
			else{
				close->next = open;
				return close;
			}
		}
		close = close->next;
		p->next = open;
		while(close->next){
			p = close;
			close = close->next;
			p->next = q;
			q = p;
		}
		close->next = p;
		return close;
	}
	else{
		return open;
	}
}

void print(Node *head){
	if (head != NULL){
		print(head ->next);
		printf("%d ", head->data);
		free(head);
		head = NULL;
	}
}

int main(){
	int rail, line;
	scanf("%d %d", &rail, &line);
	int i = 1, m = -1, n = -1;
	char instruction[22];
	char entering[6] = "enter";
	char leaf[6] = "leave";
	char migration[8] = "migrate";
	
	for(i = 1 ; i <= line; i++)
	{
		scanf("%s", instruction);
		if(instruction[0] == 'm'){
			scanf("%d", &m);
			scanf("%d", &n);
			if(n < rail && m < rail){
				TOP[n] = migrate(TOP[m], TOP[n]);
				TOP[m] = NULL;
			}
		}
		
		else if(instruction[0] == 'l'){
			scanf("%d", &m);
			if(m < rail){
				TOP[m] = deleted(TOP[m]);
			}
		}
		
		else if(instruction[0] == 'e'){
			scanf("%d", &m);
			scanf("%d", &n);
			if(m < rail){
				TOP[m] = add(TOP[m], n);
			}
		}
	}
	for(i = 0; i < rail; i++){
		print(TOP[i]);
		printf("\n");
	}
	return 0;
}
