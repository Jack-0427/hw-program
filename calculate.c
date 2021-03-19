#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define STACK_SIZE 1000002

	double num[STACK_SIZE];
	char op[STACK_SIZE];
	
	int Numtop = 0;
	int Optop = 0;
	
	typedef struct Operate{
		char postfix[STACK_SIZE];
		int digit;
	}Operate;
	
	Operate operate;
	void NumMakeEmpty(void)
	{
	  Numtop = 0;
	}
	
	void OpMakeEmpty(void)
	{
	  Optop = 0;
	}
	
	int NumIsEmpty(void)
	{
	  return Numtop == 0;
	}
	
	int OpIsEmpty(void)
	{
	  return Optop == 0;
	}
	
	int OpIsFull(void)
	{
	  return Optop == STACK_SIZE;
	}
	
	int NumIsFull(void)
	{
	  return Numtop == STACK_SIZE;
	}

	void NumPush(double f)
	{
	    num[Numtop++] = f;
	}
	
	void OpPush(char c)
	{
	    op[Optop++] = c;
	}
	
	double NumPop(void)
	{
	    return num[--Numtop];
	}
	
	char OpPop(void)
	{
	    return op[--Optop];
	}
	int priority(char op) { 
    switch(op) { 
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default:            return 0;
    } 
} 
		
void inToPostfix(char* infix, Operate* post) { 
    int j = 0, top;
    char op, c;
    char* postfix = post->postfix;
    while(*infix != '\0'){
    	op = *infix;
    	switch(op) { 
        case '(':               
			OpPush(op); 
            break; 
        case '+': case '-': case '*': case '/':
        	postfix[j++] = ' ';
   			while(priority(c = OpPop()) >= priority(op)) { 
                postfix[j++] = c;
            }
            OpPush(c);
            OpPush(op); 
            break; 
        case ')': 
            while((c = OpPop()) != '(') {  
                postfix[j++] = c;
            } 
			   
            break; 
        default:  
            postfix[j++] = op;
		}
		infix++;
	}
    while(!OpIsEmpty()) { 
        postfix[j++] = OpPop();
    }
    post->digit = j;
} 
	void transform(char p, double b, double c){
		switch(p){
			case'+':
				NumPush(b+c);
				break;
			case'-':
				NumPush(c-b);
				break;
			case'*':
				NumPush(b*c);
				break;
			case'/':
				NumPush(c/b);
				break;
		}
	}
	int calculate(Operate* postfix){
		double answer = 0.0;
		int state = 0;
		int i = 0;
		char* p = postfix->postfix;
		int check = postfix->digit;

		double a = 0.0, b = 0.0, c = 0.0, d = 0.0;
		char q;
		while(*p != '\0' && i <= check - 1){
			q = *p;
			switch(q){
				case ' ':case '+':case '-':case '*':case '/':
					if(state == 1){
						NumPush(a);
						a = 0.0;
						state = 0;
					}
					if(q != ' '){
						b = NumPop();
						c = NumPop();
						transform(q, b, c);
					}
					break;
				default:
					state = 1;
					a = 10 * a + atoi(&q);
			}
			p++;
			i++;
		}
		answer = NumPop();
		printf("%.15f\n", answer);

	}
	int main(){
		int a;
		char c;
		float answer;
		char infix[STACK_SIZE] = {'\0'};
		while(scanf("%s", infix) != EOF){
			inToPostfix(infix, &operate);
			calculate(&operate);
		}
		return 0;
	}