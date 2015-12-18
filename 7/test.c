#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char*  strrev(char *str){
	int length = strlen(str) ;
	int p1 = 0 ;
	int p2 = length - 1 ;
	if(str[p1]=='-'){
		p1++ ;
	}
	while(p2>p1){
		char temp = 0 ;
		temp =str[p1] ;
		str[p1] = str[p2] ;
		str[p2] = temp ;
		p1++ ;
		p2-- ;
	}
	return str ;
}

void removeZero(char* str){
	int i=0;
	int j=0 ;
	if(str[i]=='-'){
		i++ ;
		j++ ;
	}
	while(str[i]=='0'){
		i++ ;
	}
	while(str[i]!='\0'){
		str[j] = str[i] ;
		j++ ;
		i++ ;
	}
	str[j] = '\0' ;
}
int reverse(int x){
	char str[100] ;
	char str1[100] ;
	sprintf(str,"%d",x) ; //将整型变成字符串
	strrev(str) ;//字符串反转
	removeZero(str) ;
	int y = atoi(str) ; //将字符串变成整形
	sprintf(str1,"%d",y) ;
	if(strcmp(str,str1)){
		return 0 ;
	} 
	return y ;
}


int main(){
	int x ;
	scanf("%d",&x) ;
	x = reverse(x) ;	
	printf("%d\n",x) ;
	return 0 ;
}	
