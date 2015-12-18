#include<stdio.h>
#include<malloc.h>
int right(int*result,int* index,int** matrix,int start,int end,int row){
	for(int i=start;i<end;i++){
		result[(*index)++] = matrix[row][i] ;
	}
}

int down(int* result,int* index,int** matrix,int start,int end,int col){
	for(int i=start;i<end;i++){
		result[(*index)++] = matrix[i][col] ;
	}
}

int left(int* result,int* index,int** matrix,int start,int end,int row){
	for(int i=start;i>end;i--){
		result[(*index)++] = matrix[row][i] ;
	}
}

int up(int* result,int* index,int** matrix,int start,int end,int col){
	for(int i=start;i>end;i--){
		result[(*index)++] = matrix[i][col] ;
	}
}
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
	int index = 0 ;
	int* result = (int*)malloc((matrixRowSize)*(matrixColSize)*sizeof(int)) ;
	int upCol = -1 ;
	int upEnd = -1 ;
	int upStart;

	int rightBound = matrixColSize  ;
	int downBound = matrixRowSize ;
	int leftBound = -1 ;
	int upBound = -1 ;

	int rightStart ;
	int rightEnd ;
	int rightRow ;

	int downStart ;
	int downEnd ;
	int downCol ;

	int leftStart ;
	int leftEnd ;
	int leftRow ;

	while(index < (matrixRowSize)*(matrixColSize)){
		if(index <  (matrixRowSize)*(matrixColSize)){
			rightStart = upCol + 1 ;
			rightEnd = rightBound ;
			rightBound-- ;
			rightRow = upEnd + 1 ;
			right(result,&index,matrix,rightStart,rightEnd,rightRow) ;
		}

		if(index <  (matrixRowSize)*(matrixColSize)){
			downStart = rightRow + 1 ;
			downEnd = downBound ;
			downBound-- ;
			downCol = rightEnd - 1 ;
			down(result,&index,matrix,downStart,downEnd,downCol) ;    
		}

		if(index <  (matrixRowSize)*(matrixColSize)){
			leftStart = downCol - 1 ;
			leftEnd = leftBound ;
			leftBound++ ;
			leftRow = downEnd - 1 ;
			left(result,&index,matrix,leftStart,leftEnd,leftRow) ;
		}

		if(index <  (matrixRowSize)*(matrixColSize)){
			upStart = leftRow - 1 ;
			upEnd = rightRow ;
			upCol = leftEnd + 1 ;
			up(result,&index,matrix,upStart,upEnd,upCol) ;
		}
	}
	return result ;
	
}
int main(){
	int** matrix = (int**)malloc(sizeof(int*)*4) ;
	for(int i=0;i<4;i++){
		matrix[i] = (int*)malloc(sizeof(int)*4);
		for(int j=0;j<4;j++){
			matrix[i][j] = i*4 + j + 1 ;
		}
	}	
/*	int matrix[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}} ;
	int* temp = matrix ;
	int** p = &temp ;*/
	int* result = spiralOrder(matrix,4,4) ;
	for(int i=0;i<16;i++){
		printf("%d ",result[i]) ;
	}
	printf("\n") ;
	return 0 ;
}
