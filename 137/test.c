#include<stdio.h>
int singleNumber(int* nums, int numsSize) {
	int count[32] = {0} ;
	int result = 0 ;
	for(int i=0;i<32;i++){
		for(int j=0;j<numsSize;j++){
			count[i] =count[i]+ ((nums[j]>>i)&1) ;
		}
		result = result | ((count[i]%3)<<i) ;
	}
	return result ;
}
int main(){
	int nums[] = {2,2,3,2} ;
	int result = singleNumber(nums,4) ;
	printf("%d\n",result) ;
	return 0 ;
}
