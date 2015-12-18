#include<stdio.h>
#include<string.h>
#include<malloc.h>
char* intToRoman(int num){
	char* s[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	int index[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000} ;
	int length = 13 ;
	char* arr = (char*)malloc(sizeof(char)*100);
	arr[0] = '\0' ;
	while(num != 0 ){
		if(num >= index[length-1]){
			strcat(arr,s[length-1]) ;
			num = num - index[length-1] ;
		}else{
			length-- ;
		}
	}
	return arr ;	
} 
int main(){
	int num ;
	scanf("%d",&num) ;
	char*  s = intToRoman(num) ;
	printf("%s\n",s) ;
	return 0 ;
}
