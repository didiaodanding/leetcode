#include<stdio.h>
int removeElement(int* nums,int numsSize,int val){
	int count = 0 ;
	int backup[numsSize] ;
	for(int i=0;i<numsSize;i++){
		if(nums[i]==val){
			
		}else{
			backup[count] = nums[i] ;
			count++ ;
		}
	}
	for(int i=0;i<count;i++){
		nums[i] = backup[i] ;
	}
	return count ;
}
int main(){
	int nums[] = {4,5} ;
	int num = removeElement(nums,2,4) ;
	printf("%d",num) ;
	printf("\n") ;
	return 0 ;
}
