int removeDuplicates(int* nums, int numsSize) {
	if(numsSize==0){
		return 0;
	}
	int array[numsSize] ;
	int count = 0 ;
	for(int i=0;i<numsSize-1;i++){
		if(nums[i]==nums[i+1]){
			
		}else{
			array[count++] = nums[i] ;
		}
	}
	array[count++] = nums[numsSize-1] ;
	for(int i=0;i<count;i++){
		nums[i] = array[i] ;
	}
	return count ;  

}
