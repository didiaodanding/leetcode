#include<stdio.h>
#include<string.h>
#include<malloc.h>
char* convert(char* s,int numRows){
	char* array = (char*)malloc(sizeof(char)*1000) ;//开辟100的字符数组
	int i = 0 ; //返回数组的下标
	int n=1 ;  //记录列数
	int length = strlen(s) ; //字符串长度
	int a0 = 0 ;//初始值
	int a1 = 0 ; //初始值
	if(numRows>length){
		numRows = length ;
	}
	int d = 2*numRows - 2 ;  //等差值
	if(d==0){
		strcpy(array,s);
		return array ;
	}
	while((n-1)*d<length){
		array[i] = s[(n-1)*d] ;
		i++ ;
		n++ ;
	}
	n = 1 ;
	a0 = 1 ;
	a1 = -1 ;

	//不断改变初始值
	while(a0<numRows-1){
		while(a0+(n-1)*d<length){
			array[i] = s[a0+(n-1)*d];
			i++ ;
			if(a1+n*d<length){
				array[i] = s[a1+n*d] ;
				i++ ;
			}
			n++ ;
		}
		n = 1 ;
		a0++ ;
		a1-- ;
	}
	n = 1 ;
	while(a0+(n-1)*d<length){
		array[i] = s[a0+(n-1)*d] ;
		i++ ;
		n++ ;
	}
	array[i] = '\0' ;	
	return array ;
}

int main(){
	char s[1000] ;
	int length ;
	scanf("%s",s) ;
	scanf("%d",&length) ;
	char* array = convert(s,length) ;
	printf("%s\n",array) ;
	return 0 ;
}
