#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MAX 1000
int length = 1 ;
int carry(int a[],int i){
	if(a[i]>=10){
		a[i+1] = a[i+1] + a[i] / 10 ;
		a[i] = a[i] - a[i]/10*10 ;
		carry(a,i+1) ;
	}
	if(i>=length){
		length = i + 1 ;
	}
	return 0 ;
}
char* multiply(char* num1, char* num2) {
	length = 1 ;
	int c[MAX] ;
	memset(c,0,MAX) ;
	for(int i=0;i<strlen(num1);i++){
		for(int j=0;j<strlen(num2);j++){
			c[i+j] = (num1[strlen(num1)-1-i] -'0')* (num2[strlen(num2)-1-j] - '0') + c[i+j] ;
			carry(c,i+j) ;
		}
	}
	while(length>1&&c[length-1]==0){
		length = length - 1 ;
	}
	char* result = (char*)malloc(sizeof(char)*(length+1)) ;
	for(int i=0;i<length;i++){
		result[length-1-i] = c[i] + '0';
	}
	result[length] = '\0' ; 
	return result ; 
}
int main(){
	char* a = "9" ;
	char* b = "98" ;
	char* result = multiply(a,b) ;
	printf("%s\n",result) ;
}
