#include<stdio.h>
#include<stdint.h>
int hammingWeight(uint32_t n) {
	int left = 0 ;
	int re = 0 ;
	while(0 != n)
	{
    		left = n & 0x1;
    		re += left;
    		n = n >> 1;
	}
	return re ;
}
int main(){
	int i = 11 ; 
	int result = hammingWeight(i) ;
	printf("%d\n",result) ;
	return 0 ;
}
