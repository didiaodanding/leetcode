#include<malloc.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX 100
bool judge(int a,int b){
	return (b-a==1);
}

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
	char** result = (char**)malloc(sizeof(char*)*MAX) ;
	*returnSize = 0 ;
	int start = 0 ; 
	if(numsSize==0){
		return NULL ;
		
	}
	if(numsSize==1){
		char* resu = (char*)malloc(sizeof(char)*MAX) ;
		sprintf(resu,"%d",nums[start]) ;
		result[*returnSize] = resu ;
		(*returnSize)++ ;
		return result ;
	}

	int i = 0 ;
	for(i=0;i<numsSize-1;i++){
		if(!judge(nums[i],nums[i+1])){
			char* resu = (char*)malloc(sizeof(char)*MAX) ;
			if(i==start){
				sprintf(resu,"%d",nums[i]) ;
			}else{
				sprintf(resu,"%d->%d",nums[start],nums[i]) ;
			}
			result[*returnSize] = resu ;
			(*returnSize)++ ;
			start = i+1 ;
		}
		
	}

	if(!judge(nums[i-1],nums[i])){
		char* resu = (char*)malloc(sizeof(char)*MAX) ;
		sprintf(resu,"%d",nums[i]) ;
		result[*returnSize] = resu ;
		(*returnSize)++ ;	
	}else{
		char* resu = (char*)malloc(sizeof(char)*MAX) ;
		sprintf(resu,"%d->%d",nums[start],nums[i]) ;
		result[*returnSize] = resu ;
		(*returnSize)++ ;
	}
	return result ;
}

int main(void){
	return 0 ;
}
