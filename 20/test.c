#include<string.h>
#include<stdio.h>
#include<stdbool.h>
bool isLeft(char symbol){
	if(symbol=='(')
		return true ;
	if(symbol=='{')
		return true ;
	if(symbol=='[')
		return true ;
	return false ;
}

bool isMatch(char left,char right){
	if(left=='('&&right==')')
		return true ;
	if(left=='{'&&right=='}')
		return true ;
	if(left=='['&&right==']')
		return true ;
	return false ;
}

void setZero(char* symbol){
	*symbol = '0' ;
}


bool isValid(char* s){
	for(int i=0;i<strlen(s);i++){
		if(!isLeft(s[i])){
			int j = i-1 ;
			while(j>0&&(s[j]=='0')){
				j-- ;
			}
			if(!isMatch(s[j],s[i])){
				return false ;	
			}
			setZero(&s[j]) ;
			setZero(&s[i]) ;
		}
	}
	for(int i=0;i<strlen(s);i++){
		if(s[i]!='0')
 			return false ;
	}
	return true ;
}
int main(void){
	char s[] = "()[]{}" ;
	if(isValid(s)){
		printf("success\n") ;
	}else{
		printf("failed\n") ;
	}
	return 0 ;
}
