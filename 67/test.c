#include<stdio.h>
#include<malloc.h>
#include<string.h>
int max(int a,int b){
	if(a>b)
		return a ;
	return b ;
}
int min(int a,int b){
	if(a>b)
		return b ;
	return a ;
}
char* addBinary(char* a,char* b){
	int lengthA = strlen(a) ;
	int lengthB = strlen(b) ;
	int add = 0 ;
	int lengthMin = min(lengthA,lengthB) ;
	int lengthMax = max(lengthA,lengthB) ;
	char* temp = (char*)malloc(sizeof(char)*lengthMax) ;
	for(int i=0;i<lengthMin;i++){
		int result = (a[lengthA-1-i]-'0') + (b[lengthB-1-i]-'0') + add ;
		if(result>=2){
			temp[lengthMax-1-i] = result - 2 + '0' ;
			add = 1 ;
		}else{
			temp[lengthMax-1-i] = result+'0' ;
			add = 0 ;
		}
	}
	for(int i=lengthMin;i<lengthMax;i++){
		if(lengthMin==lengthA){
			int result = (b[lengthMax-1-i] - '0') + add ;
			if(result>=2){
				temp[lengthMax-1-i] = result - 2 + '0' ;
				add = 1 ;
			}else{
				temp[lengthMax-1-i] = result + '0' ;
				add = 0 ;
			}
		}else{
			int result = (a[lengthMax-1-i]-'0') + add ;
			if(result>=2){
				temp[lengthMax-1-i] = result - 2 + '0' ;
				add = 1 ;
			}else{
				temp[lengthMax-1-i] = result + '0' ;
				add = 0 ;
			}
		}
	}
	char* result ;
	if(add==1){
		result = (char*)malloc(sizeof(char)*(lengthMax+2)) ;
		result[0] = '1' ;
		for(int i=1;i<lengthMax+1;i++){
			result[i] = temp[i-1] ;
		}
		result[lengthMax+1] = '\0' ;
	}else{
		result = (char*)malloc(sizeof(char)*(lengthMax+1)) ;
                for(int i=0;i<lengthMax;i++){
                        result[i] = temp[i] ;
                }
                result[lengthMax] = '\0' ;

	}
	return result ;

}
int main(){
	char* a =  "11" ;
	char* b = "1" ;
	char c[] = {'1','2','\0'} ;
	char *result = addBinary(a,b) ;
	printf("%s\n",result) ;
	return 0 ;
}
