#include<stdio.h>
#include<malloc.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int add = 0 ;
	int* temp = (int*)malloc(sizeof(int)*digitsSize) ; 
	for(int i=digitsSize-1;i>=0;i--){
		if(i==digitsSize-1){
			temp[i] = digits[i] + 1 ;
		}else{
			temp[i] = digits[i] + add ;
		}
		if(temp[i]>=10){
			add = 1 ;
			temp[i] = temp[i] - 10 ;
		}else{
			add = 0 ;
		}
	}
	*returnSize = digitsSize ;
	int* result ;
	if(add==1){
		result = (int*)malloc(sizeof(int)*(digitsSize+1)) ;
		result[0] = 1 ;
		for(int i=1;i<digitsSize+1;i++){
			result[i] = temp[i-1] ;
		}
		*returnSize = digitsSize + 1 ;
		return result ;
	}
	return temp ;   
}

int main(){
	int array[] = {9,9,9} ;
	int returnSize = 0 ;
	int* result = plusOne(array,3,&returnSize) ;
	for(int i=0;i<returnSize;i++){
		printf("%d ",result[i]) ;
	}
	printf("\n") ;
}
