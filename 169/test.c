#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a ,const void* b){
	int* temp_a = (int*)a ;
	int* temp_b = (int*)b ;
	if(*temp_a>*temp_b) return 1 ;
	if(*temp_a<*temp_b) return -1 ;
	return 0 ;
}
int majorityElement(int* nums,int numsSize){
 qsort(nums,numsSize,sizeof(int),cmp) ;
        int count = 1 ;
        for(int i=0;i<numsSize-1;i++){
                if(nums[i]==nums[i+1]){
                        count++ ;
                        if(count>numsSize/2){
                                return nums[i] ;
                        }
                }else{
                        count = 1 ;
                }
        }
        return nums[0];
}


int main(){
	int nums[] = {3,3,4} ;
	int num = majorityElement(nums,3) ;
	printf("%d\n",num) ;
	return 0 ;
}
