#include<stdio.h>
int singleNumber(int* nums, int numsSize) {
	if(numsSize<1){
		return 0 ;
	}
	int result = 0 ;
	for(int i=0;i<numsSize;i++){
		result = result ^ nums[i] ;
	}
	return result; 
}
int main(){
	int nums[] = {1,3,3,4,2,1,4} ;
	int result = singleNumber(nums,7) ;
	printf("%d\n",result) ;
	return 0 ;
}
