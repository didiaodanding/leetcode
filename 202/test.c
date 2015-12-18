#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX 100 
//这道题不适合c语言，因为没有set数据结构，可以使用hash表
bool isHappy(int n) {
	int array[MAX] ;
	int index = 0 ;
	char str[100] ;
	while(n!=1){
		int sum = 0 ;
		sprintf(str,"%d",n) ;
		for(int i=0;i<strlen(str);i++){
			sum += (str[i]-'0')*(str[i]-'0') ;
		}
		for(int i=0;i<index;i++){
			if(sum==array[index])
				break ;
		}
		n = sum ;
	}	
	if(n==1){
		return true ;
	}else{
		return false ;
	}
}
int main(){
	bool result = isHappy(7) ;
	if(result){
		printf("is a happy number\n") ;
	}else{
		printf("is not a happy number\n") ;
	}
}
