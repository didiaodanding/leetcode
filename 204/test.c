//一个合数肯定能分解成质数
#include<stdio.h>
#include<math.h>
int countPrimes(int n){
	if(n<=2) return 0 ;
	int count = 0 ; //2是质数
        int prime[700000] ; //保存质数，最多100000个
        prime[0] = 2 ;
        for(int k=3;k<n;k++){
                int i = 0 ;
		int s = (int)sqrt(k) ;
                for(;i<count&&((k%prime[i])!=0);i++){
			if(prime[i]>s){
				prime[count] = k ;
				count ++ ;
				break ;
			}
                }
        }
        return count ;
}
int main(){
	int number ;
	scanf("%d",&number) ;  //输入的最大数字
	int count = countPrimes(number) ;
	printf("%d\n",count) ;
	return 0 ;
}
