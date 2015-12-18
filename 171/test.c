#include<string.h>
int stoi(char symbol){
	return symbol-'A'+1 ;
}

int titleToNumber(char* s){
	int num = 0 ;
	for(int i=0;i<strlen(s);i++){
		num = num*26 + stoi(s[i]) ;
	}
	return num ;
}
int main(void){

	return 0 ;
}
