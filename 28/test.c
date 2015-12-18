#include<stdio.h>
#include<string.h>
//传统的都是KMP算法，下面使用的不是KMP算法，但是也可以accept
int strStr(char* haystack,char* needle){
	int lengthA = strlen(haystack) ;
	int lengthB = strlen(needle);
	int i,j ;
	for(i=j=0;i<lengthA&&j<lengthB;){
		if(haystack[i]==needle[j]){
			i++ ;
			j++ ;
		}else{
			i -= j-1 ;
			j = 0 ;
		}
	}
	return (j !=lengthB) ? -1 : i-j ;
}
int main(){
	char* haystack = "1234" ;
	char* needle = "234" ;
	int result = strStr(haystack,needle) ;
	printf("%d\n",result) ;
	return 0 ;
}

