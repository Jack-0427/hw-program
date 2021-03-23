#include <stdlib.h>
#include <string.h>
#include <stdio.h>

	struct node{
		int data;
		struct node* next;
		struct node* prev;
	};
	
	typedef struct node Node;
	
	Node* TOP[1000] = {NULL};
	Node* TAIL[1000] = {NULL};

void print(Node* top, Node* tail){
	while(tail){
		printf("%d ", tail->data);
		if(tail->prev == NULL && tail->next == NULL){
			tail = NULL;
		}
		else if(tail->prev){
			if(tail->prev->prev == tail){
				tail = tail->prev;
				tail->prev = NULL;				
			}
			else{
				tail = tail->prev;
				tail->next = NULL;
			}
		}
		else if(tail->next){
			if(tail->next->next == tail){
				tail = tail->next;
				tail->next = NULL;
			}
			else{
				tail = tail->next;
				tail->prev = NULL;
			}
		}
	}
}

	int main(){
		int rail, line;
		int state = -1;
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
					if(TOP[m] == NULL){
						continue;
					}
		
					else if(TOP[n] == NULL){	 
						TOP[n] = TAIL[m];
						TAIL[n] = TOP[m];
						TAIL[m] = NULL;
						TOP[m] = NULL;
						continue;
					}
		
					else if(TOP[m]->next == NULL){
						TOP[m]->next = TOP[n];
						if(TOP[n]->prev == NULL){
							TOP[n]->prev = TOP[m];
							TOP[n] = TAIL[m];
							TAIL[m] = NULL;
							TOP[m] = NULL;
							continue;
						}
						else{
							TOP[n]->next = TOP[m];
							TOP[n] = TAIL[m];
							TAIL[m] = NULL;
							TOP[m] = NULL;
							continue;
						}
					}
					else if(TOP[m]->prev == NULL){
					 	TOP[m]->prev = TOP[n];
						if(TOP[n]->next == NULL){
							TOP[n]->next = TOP[m];
							TOP[n] = TAIL[m];
							TAIL[m] = NULL;
							TOP[m] = NULL;
							continue;
						}
						else{
							TOP[n]->prev = TOP[m];
							TOP[n] = TAIL[m];
							TAIL[m] = NULL;
							TOP[m] = NULL;
							continue;
						}
					}
				}
			}
			
			else if(instruction[0] == 'l'){
				scanf("%d", &m);
				if(m < rail){
					if(!TOP[m]){
						continue;
					}
					else if(TOP[m]->prev){
						if(TOP[m]->prev->prev == TOP[m]){
							Node* p = TOP[m];
							p = p->prev;
							free(TOP[m]);
							p->prev = NULL;
							TOP[m] = p;
							p = NULL;
						}
						else{
							Node* tmp = TOP[m];
							TOP[m] = TOP[m]->prev;
							free(tmp);
							tmp = NULL;
							TOP[m]->next = NULL;
						}
					}
					else if(TOP[m]->next){
						if(TOP[m]->next->next == TOP[m]){
							Node* p = TOP[m];
							p = p->next;
							free(TOP[m]);
							p->next = NULL;
							TOP[m] = p;
							p = NULL;
						}
						else{
							Node* tmp = TOP[m];
							TOP[m] = TOP[m]->next;
							free(tmp);
							tmp = NULL;
							TOP[m]->prev = NULL;
						}
					}
					else{
						TOP[m] = NULL;
						TAIL[m] = NULL;
					}
				}		
			}
			
			else if(instruction[0] == 'e'){
				scanf("%d", &m);
				scanf("%d", &n);
				if(m < rail){
	if(TOP[m] == NULL || TOP[m]->next || ((TOP[m]->next == NULL) && (TOP[m]->prev == NULL))){
			Node* newer = (Node*)malloc(sizeof(Node));
			newer->next = TOP[m] ;
			newer->data = n;
			if(TOP[m]){
				TOP[m]->prev = newer;
			}
			TOP[m] = newer;	
			TOP[m]->prev = NULL;
			if(TOP[m]->next == NULL && TOP[m]->prev == NULL){
				TAIL[m] = TOP[m];
			}
		}
		
		else if(TOP[m]->prev){
			Node* newer = (Node*)malloc(sizeof(Node));
			newer->prev = TOP[m];
			newer->data = n;
			TOP[m]->next = newer;
			TOP[m] = newer;
			TOP[m]->next = NULL;
		}
					
				}
				
			}
		}
		for(i = 0; i < rail; i++){
			print(TOP[i], TAIL[i]);
			printf("\n");
		}
		return 0;
}
