#include<stdio.h>
int createArray(int length){
	int array[length] ;
	for(int i=0;i<length;i++){
		array[i] = i ;
	}
	for(int i=0;i<length;i++){
		printf("%d\n",i) ;
	}
}
int main(){
	createArray(5) ;
	return 0 ;
}
