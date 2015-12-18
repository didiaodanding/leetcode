#include<stdio.h>
#include<malloc.h>
struct map{
	int index ;
	int value ;
} ;

struct map* create(int* nums,int numSize){
	struct map* m = (struct map*)malloc(sizeof(struct map)*numSize) ;
	for(int i=0;i<numSize;i++){
		m[i].index = i ;
		m[i].value = nums[i] ;
	}
	return m ;
}
int cmp(const void* a , const void* b){
	struct map* temp_a = (struct map*)a ;
	struct map* temp_b = (struct map*)b ;
	return temp_a->value - temp_b->value ;
}
int* twoSum(int* nums,int numsSize,int target,int* returnSize){
	struct map* ma = create(nums,numsSize) ;
//	for(int i=0;i<numsSize;i++){
//		printf("%d ",ma[i].value) ;
//	}
//	printf("\n") ;
	qsort(ma,numsSize,sizeof(struct map),cmp) ;
//	for(int i=0;i<numsSize;i++){
//		printf("%d ",ma[i].value) ;
//	}
//	printf("\n") ;
	int* result = (int*)malloc(sizeof(int)*2) ;
	for(int i=0;i<numsSize;i++){
		for(int j=i+1;j<numsSize;j++){
			if(ma[i].value+ma[j].value==target){
				if(ma[i].index<ma[j].index){
					result[0] = ma[i].index+1 ;
					result[1] = ma[j].index+1 ;
				}else{
					result[0] = ma[j].index+1 ;
					result[1] = ma[i].index+1 ;
				}
				*returnSize = 2 ;
				return result ;
			}
			if(ma[i].value+ma[j].value>target){
				break ;
			}
		}
	}
	return NULL ;
}

int main(){
	int* array ;
	int  numbers[]={-1,-2,-3,-4,-5} ;
	int target = -8 ;
	int returnSize ;
	array =  twoSum(numbers,5,target,&returnSize) ;
	printf("%d\n",array[0]) ;
	printf("%d\n",array[1]) ;
	return 0 ;
}
