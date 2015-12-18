#include<stdio.h>
int climbStairs(int n) {
 	if(n<=0)
		return 0;
	if(n==1)
		return 1 ;
	if(n==2)
		return 2 ;
	int sum[n+1] ;
	sum[1] = 1 ;
	sum[2] = 2 ; 
	for(int i=3;i<=n;i++){
		sum[i] = sum[i-2]+sum[i-1] ;
	}  
	return sum[n] ; 
}

int main(){
	int result = climbStairs(3) ;
	printf("%d\n",result) ;
	return 0;
}
