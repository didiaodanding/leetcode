#include<stdbool.h>
#include<stdlib.h>
int cmp(const void* i , const void* j){
	int* a = (int*) i ;
	int* b = (int*) j ;
	if(*a>*b)
		return 1 ;
	if(*a<*b)
		return -1 ;
	return 0 ;
}
bool containsDuplicate(int* nums, int numsSize) {
	qsort(nums,numsSize,sizeof(int),cmp) ;
	for(int i=0;i<numsSize-1;i++){
		if(nums[i]==nums[i+1])
			return true ;
	}
	return false ;
}

int main(void){
	return 0 ;
}
