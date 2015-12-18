#include<stdio.h>
#include<string.h>
#include<malloc.h>
int* productExceptSelf(int* nums,int numsSize,int* returnSize){
	int pro[numsSize] ;
	int product = 1 ;
	for(int i=0;i<numsSize;i++){
		product = product * nums[i] ;
		pro[i] = product ;
	}

	int revt[numsSize] ;
	product = 1 ;
 	for(int i=numsSize-1;i>=0 ;i--){
		product = product * nums[i] ;
		revt[i] = product ;
	}

	int* result = (int*)malloc(sizeof(int)*numsSize) ;
	result[0] = revt[1] ;
	for(int i=1;i<numsSize-1;i++){
		result[i] = pro[i-1] * revt[i+1] ;
	}
	result[numsSize-1] = pro[numsSize-2] ;
	*returnSize = numsSize ;	
	return result ;
}

int main(void){
	int nums[] = {3,4,5,6} ;
	int returnSize = 0 ;
	int numsSize = 4 ;
	int* result = productExceptSelf(nums,numsSize,&returnSize) ;
	if(result!=NULL){
		for(int i=0;i<returnSize;i++){
			printf("%d\n",result[i]) ;
		}
	}
	return 0 ;
}
