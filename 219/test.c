#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int cmp(const void* i , const void* j){
        int* a = (int*) i ;
        int* b = (int*) j ;
        if(*a>*b)
                return 1 ;
        if(*a<*b)
                return -1 ;
        return 0 ;
}

bool scan(int* nums,int start, int end) {
    int new[end-start] ;
	for(int i=start;i<end;i++){
		new[i-start] = nums[i] ;
	}
     qsort(new,end-start,sizeof(int),cmp) ;
        for(int i=0;i<end-start-1;i++){
                if(new[i]==new[i+1])
                        return true ;
        }
        return false ;

}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
	if(numsSize==0)
		return false ;
	if(numsSize==1)
		return false ;	
	if(k==0)
		return false ;
	int start = 0 ;
	int end = numsSize ;
	while(start<end-k){
		if(scan(nums,start,start+k+1))
			return true ;
		start++ ;
	}

	if(scan(nums,start,end))
		return true ;
	return false ;	
}

int main(void){
	int nums[] = {1,2} ;
	bool flag = containsNearbyDuplicate(nums,2,2) ;
	if(flag==true){
		printf("success\n") ;
	}else{
		printf("failed\n") ;
	}
	return 0 ;
}
