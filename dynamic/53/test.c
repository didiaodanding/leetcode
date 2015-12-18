#include<stdio.h>
int maxSubArray(int* nums, int numsSize) {
	int sum[numsSize] ;
	sum[0] = nums[0] ;
	for(int i=1;i<numsSize;i++){
		sum[i] = nums[i] + sum[i-1] ;
	}
	int m[numsSize][numsSize] ;
	int max = 0 ;
	for(int i=0;i<numsSize;i++){
		for(int j=0;j<numsSize;j++){
			int temp  = nums[i] + sum[j] - sum[i] ;
			if(temp>max){
				max = temp ;	
			}
		}
	}   
	return max ;
}
int main(){
	int array[] = {-2,1,-3,4,-1,2,1,-5,4} ;
	int result = maxSubArray(array,9) ;
	printf("%d\n",result) ;
}
