#include<stdio.h>
void merge(int* nums1, int m, int* nums2, int n) {
	int array[m+n] ;
	int index = 0 ;
	//nums1数组
	int i = 0 ;
	//nums2数组
	int j = 0 ;
	while(index<m+n){
		if(i<m&&j<n&&nums1[i]<nums2[j]){
			array[index++] = nums1[i++] ;
		}else if(i<m&&j<n&&nums1[i]>=nums2[j]){
			array[index++] = nums2[j++] ;
		}else if(i==m){
			array[index++] = nums2[j++] ;
		}else if(j==n){
			array[index++] = nums1[i++] ;
		}
	}
	for(int k=0;k<index;k++){
		nums1[k] = array[k] ;
	}
}
int main(){
	return 0 ;
}
