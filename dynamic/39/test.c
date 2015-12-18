#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 100
struct cell{
	int scount ;
	int** sresult ;
	int* scolumnSizes ;
	int sreturnSize ;
};
int getRow(int* candidates,int candidatesSize,int target){
 	int i=0 ;
        for(i=0;i<candidatesSize;i++){
                if(candidates[i]>target){
                        break ;
                }
        }
        return i ;

}

int cmp(const void* i,const void* j){
	int* a = (int*)i ;
	int* b = (int*)j ;
	if(*a>*b)
		return 1 ;
	if(*a<*b)
		return -1 ;
	return 0 ;
}
//目标数字是0，含有0项不可能
//所以初始化为0
int* copy(int* source,int length){
	int *result = (int*)malloc(sizeof(int)*MAX) ;
	for(int i=0;i<length;i++){
		result[i] = source[i] ;
	}
	return result ;
}
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
	qsort(candidates,candidatesSize,sizeof(int),cmp) ;
	int row =getRow(candidates,candidatesSize,target) ;
        struct cell  m[MAX][MAX] ;
        for(int i=0;i<row;i++){
                (m[i][0]).scount = 0 ;
        }
        for(int j=1;j<=target;j++){
                for(int i=0;i<row;i++){
         		int sum = 0 ;
			m[i][j].sresult = (int**)malloc(MAX*sizeof(int*)) ;
			m[i][j].scolumnSizes = (int*)malloc(MAX*sizeof(int)) ;
                        if(j%candidates[i]==0){
				int number = j / candidates[i] ;
				int* temp = (int*)malloc(sizeof(int)*MAX) ;
				int nu = 0 ;
				for(nu=0;nu<number;nu++){
					temp[nu] = candidates[i] ;
				}
				m[i][j].sreturnSize = 0 ;
				(m[i][j].sresult)[m[i][j].sreturnSize] = temp ;
				(m[i][j].scolumnSizes)[m[i][j].sreturnSize] = nu ;
				(m[i][j].sreturnSize)++ ; 			
                                sum = 1 ;
                         }else{
				m[i][j].sreturnSize = 0 ;
                         }
                         if(i>0){
                                int bound = j / candidates[i] ;
                                for(int n=0;n<=bound;n++){
                                	sum =sum + m[i-1][j-n*candidates[i]].scount ;
					for(int ot=0;ot<m[i-1][j-n*candidates[i]].sreturnSize;ot++){
//						(m[i][j].sresult)[m[i][j].sreturnSize] = (m[i-1][j-n*candidates[i]].sresult)[ot] ;
						(m[i][j].sresult)[m[i][j].sreturnSize] =  copy((m[i-1][j-n*candidates[i]].sresult)[ot], (m[i-1][j-n*candidates[i]].scolumnSizes)[ot] ) ;
						(m[i][j].scolumnSizes)[m[i][j].sreturnSize] = (m[i-1][j-n*candidates[i]].scolumnSizes)[ot] ;
						for(int le=0;le<n;le++){
							((m[i][j].sresult)[m[i][j].sreturnSize])[(m[i][j].scolumnSizes)[m[i][j].sreturnSize]] = candidates[i] ;
							(m[i][j].scolumnSizes)[m[i][j].sreturnSize]  = (m[i][j].scolumnSizes)[m[i][j].sreturnSize] + 1 ;
						}
						(m[i][j].sreturnSize)++ ;
					}
				}
				if(i>1){
					
				}

                        }
                  	m[i][j].scount = sum ;
                }
        }
	if(row>1){
		*columnSizes = m[row-1][target].scolumnSizes ;
		*returnSize = m[row-1][target].sreturnSize ;
       		 return m[row-1][target].sresult ;
	}else{
		return NULL ;
	}

}
int main(){
	int candidates[] = {7,12,5,10,9,4,6,8} ;
        int candidatesSize = 8 ;
        int target = 32 ;
	int* columnSizes ;
	int returnSize ;
        int** result = combinationSum(candidates,candidatesSize,target,&columnSizes,&returnSize) ;
	if(result==NULL){
		printf("no result\n") ;
	}
	for(int i=0;i<returnSize;i++){
		for(int j=0;j<columnSizes[i];j++){
			printf("%d ",result[i][j]) ;
		}
		printf("\n") ;
	}
        return 0 ;
}
