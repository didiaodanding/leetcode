#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool isPalindrome(int x){
	char buf[100] ;
	if(x<0){
		return false ;
	}
	sprintf(buf,"%d",x) ;
	int i = 0 ;
	int j = strlen(buf)-1 ;
	while(i<j){
		if(buf[i]==buf[j]){
			
		}else{
			return false ;
		}
		i++ ;
		j-- ;
	}
	return true ;
}

int main(){
	int x ; 
	scanf("%d",&x) ;
	bool flag = isPalindrome(x) ;
	if(flag){
		printf("This is a palindrome\n") ;
	}else{
		printf("This is not a palindrome\n") ;
	}
	return 0 ;
}
