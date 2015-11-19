#include<stdio.h>
int min(int a,int b){
	if(a>b)
		return b ;
	return a ;
}
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
	int m[triangleRowSize][triangleRowSize] ;
	if(triangleRowSize<0){
		return 0 ;
	}else{
		m[0][0] = triangle[0][0] ;
		for(int i=1;i<triangleRowSize;i++){
			m[i][0] = m[i-1][0] + triangle[i][0] ;
			for(int j=1;j<triangleColSizes[i]-1;j++){
				m[i][j] = min(m[i-1][j-1]+triangle[i][j],m[i-1][j]+triangle[i][j]) ;
			}
			m[i][triangleColSizes[i]-1] = m[i-1][triangleColSizes[i-1]-1] + triangle[i][triangleColSizes[i]-1] ;
		}
	}
	int min = 10000 ;
	for(int i=0;i<triangleRowSize;i++){
		if(m[triangleRowSize-1][i]<min){
			min = m[triangleRowSize-1][i] ;
		}
	}
	return min ;
}
int main(){
	
	return 0 ;
}
