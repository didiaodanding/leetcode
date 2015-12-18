#include<stdio.h>
#include<malloc.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
char* countAndSay(int n) {
	//保存结果
	char* str = (char*)malloc(MAX*sizeof(char)) ;
	str[0] = '1' ;
	str[1] = '\0' ;
	//保存上一次的数字
	char array[MAX] ;
	//结果索引
	int index = 0 ;
	//循环n次
	for(int i=1;i<n;i++){
		index = 0 ;
		strcpy(array,str) ;
		for(int j=0;j<strlen(array);j++){
			int counter = 1 ;
			while(j+1<strlen(array)&&(array[j]==array[j+1])){
				counter++ ;
				j++ ;
			}
			str[index++] = counter+'0' ;
			str[index++] = array[j] ;
		}
		str[index++] = '\0' ;
	}
	return str ;
}
int main(){
	char* s = countAndSay(6) ;
	printf("%s\n",s) ;
	return 0 ;
}	
