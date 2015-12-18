#include<stdio.h>
int max(int a,int b){
	if(a>b){
		return a ;
	}else{	
		return b ;
	}
}
//状态转移方程
//m[j] = max(m[j-1],max((m[j-k]+house[j])) 2<=k<=j 
//j表示盗取第j个房子
//house[j]表示第j个房子的钱
//m[j]表示盗取第j个房子总共所盗取的最大的钱数
int rob(int* nums, int numsSize) {
	if(numsSize<1){
		return 0 ;
	}else if(numsSize==1){
		return nums[0] ;
	}else if(numsSize == 2){
		return max(nums[0],nums[1]) ;
	}else{
		int m[numsSize] ;
		//初始化
		m[0] = nums[0] ;
		m[1] = nums[1] ;
		for(int j=2;j<numsSize;j++){
			int maxNumber = 0 ;
			for(int k=2;k<=j;k++){
				if(m[j-k]>maxNumber){
					maxNumber = m[j-k] ;
				}
			}
			m[j] = max(m[j-1],maxNumber+nums[j]) ;
		}
		return m[numsSize-1] ;
	}
}
int main(void){
	int nums[] = {2,1,1,2} ;
	int result = rob(nums,4) ;	
	printf("%d\n",result) ;
	return 0 ;
}
