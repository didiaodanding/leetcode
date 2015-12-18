#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int cmp(const void* i, const void* j){
	char *a = (char*)i ;
	char *b = (char*)j ;
	if(*a>*b)
		return 1 ;
	if(*a<*b)
		return -1 ;
	return 0 ;
}
bool isAnagram(char* s,char* t){
	if(!(strlen(s)==strlen(t)))
		return false ;
	qsort(s,strlen(s),sizeof(char),cmp) ;
	qsort(t,strlen(t),sizeof(char),cmp) ;
	for(int i=0;i<strlen(s);i++){
		if(!(s[i]==t[i]))
			return false ;
	}
	return true ;
}

int main(void){
	char s[10] = "ab" ;
	char t[10] = "ba" ;
	if(isAnagram(s,t)){
		printf("success\n") ;
	}else{
		printf("failed\n") ;
	}
	return 0 ;
}
