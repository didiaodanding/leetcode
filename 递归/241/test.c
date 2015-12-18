#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void* i,const void* j){
	int* a = (int *) i ;
	int* b = (int *) j ;
	if(*a>*b)
		return 1 ;
	if(*a<*b)
		return -1 ;
	return 0 ;
}
bool isdigital(char symbol){
	if(symbol>='0'&&symbol<='9'){
		return true ;
	}
	return false ;
}

bool computeTerminate(char* input){
	int length = strlen(input) ;
	for(int i=0;i<length;i++){
		if(!isdigital(input[i]))
			return false ;
	}
	return true ;
}

char* subString(char* input,int start ,int end){
	char* temp = (char*)malloc(sizeof(char)*(end-start+1)) ;
	for(int i=0;i<(end-start);i++){
		temp[i] = input[start+i] ;
	}
	temp[end-start] = '\0' ;
	return temp ;
}

int computeResult(int a,int b,char op){
	switch(op){
		case '+': return a+b ;
		case '-': return a-b ;
		case '*': return a*b ;
	}
}

//左右递归，终止条件只包含一个数，不包含符号时
int* diffWaysToCompute(char* input,int* returnSize){
	//只包含了一个数
	if(computeTerminate(input)){	
//		result[*returnSize] = atoi(input) ;
//		(*returnSize)++ ;
//		return result ;	
		int* result = (int *)malloc(sizeof(int)*1) ;
		result[0] = atoi(input) ;
                *returnSize = 1 ;
                return result ;
	}

	int* result = (int *)malloc(sizeof(int)*1500) ;
	for(int i=0;i<strlen(input);i++){
		if(!isdigital(input[i])){
			int lSize = 0 ;
			int RSize = 0 ;
			char* left = subString(input,0,i) ;
			char* right = subString(input,i+1,strlen(input)) ;
			int* l = diffWaysToCompute(left,&lSize) ;
			int* r = diffWaysToCompute(right,&RSize) ;
			for(int j=0;j<lSize;j++)
				for(int k=0;k<RSize;k++){
					result[*returnSize] = computeResult(l[j],r[k],input[i]) ;
					(*returnSize)++ ;
				}
		}
	}
	int* temp = (int*)malloc(sizeof(int)*(*returnSize-1)) ;
	for(int i=0;i<*returnSize;i++){
		temp[i] = result[i] ;
	}
	free(result) ;
	//释放result所指向的空间----告诉系统，这个空间可以被重新分配了。此时result本身的值（即所指向的空间不变）
	//所以为了保证指针的安全性，通常都会在free(result);之后紧跟一句result=NULL,避免result再次操作到原来的空间。
	result = NULL ;
	return temp ;	
}

int main(void){
	char array[20] = "1-2+3*4-5*6-7+8*9" ; 
	int returnSize = 0 ;
	int* result = NULL ;
	result = diffWaysToCompute(array,&returnSize) ;
	qsort(result,returnSize,sizeof(int),cmp) ;
	for(int i=0;i<returnSize;i++){
		printf("%d ",result[i]) ;
	}
	printf("\n") ;
	return 0 ;
}
