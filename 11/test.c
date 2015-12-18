//双指针法
//短板效应
#include<stdio.h>
int maxArea(int* height,int heightSize){
	int i = 0 ;
	int j = heightSize - 1 ;
	int maxArea = 0 ;
	int area = 0 ;
	while(i<j){
		if(height[i]>height[j]){
			area = (j-i)*height[j] ;
			if(maxArea<area){
				maxArea = area ;	
			}
			j-- ;
		}else{
			area = (j-i)*height[i] ; 
			if(maxArea<area){
				maxArea = area ;
			}
			i++ ;
		}
	}
	return maxArea ;
}

int main(){
	int height[] = {1,2,1} ;
	int area = maxArea(height,3) ;
	printf("%d\n",area) ;
	return 0 ;
}

