#include<stdio.h>
int removeDuplicates(int* nums, int numsSize) {
	if(numsSize==0){
		return 0;
	}
	int array[numsSize] ;
	int count = 0 ;
	int cou = 0 ;
	for(int i=0;i<numsSize-1;i++){
		if(nums[i]==nums[i+1]){
			if(cou<1){
				array[count++] = nums[i] ;
				cou++ ;
			}else{

			}
		}else{
			cou = 0 ;
			array[count++] = nums[i] ;
		}
	}
	array[count++] = nums[numsSize-1] ;
	for(int i=0;i<count;i++){
		nums[i] = array[i] ;
	}
	return count ;  

}

int main(){
	int nums[] = {1,1,1,2,2,3} ;
	int result = removeDuplicates(nums,6) ;
	for(int i=0;i<result;i++){
		printf("%d ",nums[i]) ;
	}
	printf("\n") ;
	return 0 ;
}
