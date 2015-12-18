#include<stdio.h>
int max(int a,int b){
	if(a >= b){
		return a ;
	}else{
		return b ;
	}
}
int maxSubArray(int* nums, int numsSize) {
	int sum[numsSize] ;
	sum[0] = nums[0] ;
	for(int i=1;i<numsSize;i++){
		sum[i] = max(sum[i-1]+nums[i],nums[i]) ;
	}
	int max = -10000 ;
	for(int i=0;i<numsSize;i++){
		if(sum[i]>max){
			max = sum[i] ;
		}
	}
	return max ;
}

int main(){
	int nums[] = {-2,1,-3,4,-1,2,1,-5,4} ;
	int result = maxSubArray(nums,9) ;
	printf("%d\n",result) ;
	return 0 ;
}
