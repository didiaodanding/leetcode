#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int myAtoi(char* str){
	char array[100] ;
	//str = 2147483648
	//x = -2147483648
	int x = atoi(str) ;
	//处理空格
	int i =  0 ;
	while(str[i]==' '){
		i++ ;
	}
	int j = 0 ;
	while(str[i]!='\0'){
		str[j] = str[i] ;
		j++ ;
		i++ ;
	}
	str[j] = '\0' ;
	
	int length = strlen(str) ;
	if(length == 0){
		return 0 ;
	}
	if(length==1){
		if(str[0]>='0'&&str[0]<='9'){

		}else{
			return 0 ;
		}
	}
	if(length>=2){
		if((str[1]>='0'&&str[1]<='9')||(str[0]>='0'&&str[0]<='9')){

		}else{
			return 0 ;
		}
	}	
	//处理0
	i = 0 ;
	j = 0 ;
	if(str[0]=='-'){
		i++ ;
                j++ ;
	        while(str[i]=='0'){
	       		 i++ ;
             	 }
             	 while(str[i]!='\0'&&str[i]>='0'&&str[i]<='9'){
                	 str[j] = str[i] ;
                	 j++ ;
                	 i++ ;
              	}
              	str[j] = '\0' ;
        }else{
		while(str[i]=='+'||str[i]=='0'){
			i++ ;
		}
		while(str[i]!='\0'&&str[i]>='0'&&str[i]<='9'){
			str[j] = str[i] ;
			j++ ;
			i++ ;
		}
		
		str[j] = '\0' ; 
	}
	length = strlen(str) ;
	if(length==0){
		str[0] = '0' ;
		str[1] = '\0' ;
	}
	if(length==1&&str[0]=='-'){
		str[0] = '0' ;
                str[1] = '\0' ;
	}	
	//将x变成字符串
	sprintf(array,"%d",x) ;
	if(strcmp(str,array)){//溢出了
		if(str[0]!='-'){
			x = 2147483647 ;
		}else{
			x = -2147483648 ;
		}
	}
	return x ;
}
int main(){
	char s[100] ;
	scanf("%s",s) ;
	int x = myAtoi(s) ;
	printf("%d\n",x) ;
	return 0 ;
}
