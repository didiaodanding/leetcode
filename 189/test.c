#include<stdio.h>
void rotate(int* nums, int numsSize, int k) {
	k = k % numsSize ;
	int temp[k] ;
	for(int i=numsSize-1;i>=numsSize-k;i--){
		temp[numsSize-1-i] = nums[i] ;
	}
	for(int i=numsSize-k-1;i>=0;i--){
		nums[i+k] = nums[i] ;
	}
	for(int i=k-1;i>=0;i--){
		nums[k-1-i] = temp[i] ;
	}
}
int main(){
	int nums[] = {1,2,3,4,5,6,7} ;
	rotate(nums,7,3) ;
	for(int i=0;i<7;i++){
		printf("%d\n",nums[i]) ;
	}
	return 0 ;
}
