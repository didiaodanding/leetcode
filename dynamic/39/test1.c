#define MAX 100
#include<stdio.h>
int getRow(int* candidates,int candidatesSize,int target){
	int i=0 ;
        for(i=0;i<candidatesSize;i++){
                if(candidates[i]>target){
                        break ;
                }
        }
        return i ;
}
int combinationSum(int* candidates, int candidatesSize, int target){
	int row =getRow(candidates,candidatesSize,target) ;
        int m[MAX][MAX] ;
        for(int i=0;i<row;i++){
                m[i][0] = 0 ;
        }
        for(int j=1;j<=target;j++){
                for(int i=0;i<row;i++){
                                int sum = 0 ;
                                if(j%candidates[i]==0){
                                     sum = 1 ;
                                }else{

                                }
                                if(i>0){
                                        int bound = j / candidates[i] ;
                                        for(int n=0;n<=bound;n++){
                                                sum =sum + m[i-1][j-n*candidates[i]] ;
                                        }
                                }
                                m[i][j] = sum ;
                }
        }
	return m[row-1][target] ;

}

int main(){
	int candidates[] = {8,10,6,3,4,12,11,5,9} ;
	int candidatesSize = 9;
	int target =28  ;
	int result = combinationSum(candidates,candidatesSize,target) ;
	printf("%d\n",result) ;
	return 0 ;
}
