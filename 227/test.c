#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX 100 
struct stack{
	int element[MAX] ;
	int top ;
		
};

void push(struct stack* s,int val){
	if(s->top==MAX-1){
		printf("stack overflow") ;
		return ;
	}
	
	s->element[s->top] = val ;
	(s->top)++ ;
	
}

int pop(struct stack* s){
	if(s->top==0){
		printf("empty stack") ;
		return 0;
	}
	return s->element[--(s->top)] ;
}

bool isoperation(char symbol){
	if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'){
		return true ;
	}
	return false ;
}

bool isPush(struct stack *s,char symbol){
	if(s->top==0){
		return true ;
	}
	if(s->element[s->top-1] == '*' || s->element[s->top-1] =='/')
		return false ;

	if(symbol=='+'|| symbol=='-')
		return false ;

	return true ;	
}

int compute(char op,int val1,int val2){
	switch(op){
		case '+':
			return val1+val2 ;
		case '-':
			return val1-val2 ;
		case '*':
			return val1*val2 ;
		case '/':
			return val1/val2 ;
	}
}

int calculate(char* s){
	//操作数
	struct stack operator ;
	//操作符
	struct stack operation ;
	
	operator.top = 0 ;
	operation.top = 0 ;

	for(int i=0;i<strlen(s);i++){
		if(!isoperation(s[i])){
			int number = 0 ;
			while(i<strlen(s)&&!isoperation(s[i])){
				number = number*10 + (s[i]-'0') ;
				i++ ;
			}
			push(&operator,number) ;
			if(i<strlen(s)){
				while(!isPush(&operation,s[i])){
					char op = pop(&operation) ;
					int val2 = pop(&operator) ;
					int val1 = pop(&operator) ;
					int result = compute(op,val1,val2) ;
					push(&operator,result) ;
				}
			
				push(&operation,s[i]) ;
			}
		}
	}

	while(operation.top!=0){
		 char op = pop(&operation) ;
                 int val2 = pop(&operator) ;
                 int val1 = pop(&operator) ;
                 int result = compute(op,val1,val2) ;
                 push(&operator,result) ;
	}
	return pop(&operator) ;
}

int main(){
	char *s = "1+7-7+3+3+6-3+1-8-2" ;
	int result = calculate(s) ;
	printf("%d\n",result) ;
	return 0 ;
}
