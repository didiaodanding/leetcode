//  switch (ch) {  
//            case 'I': return 1;  
//           case 'V': return 5;  
//            case 'X': return 10;  
//            case 'L': return 50;  
//            case 'C': return 100;  
//            case 'D': return 500;  
//            case 'M': return 1000;  
//   }
#include<stdio.h>
int toNum(char ch){
	switch (ch) {  
       	    case 'I': return 1;  
            case 'V': return 5;  
            case 'X': return 10;  
            case 'L': return 50;  
            case 'C': return 100;  
            case 'D': return 500;  
            case 'M': return 1000;  
  	 }

}
int romanToInt(char* s){
	int i = 0 ;
	int sum = 0 ;
	while(s[i]!='\0'){
		sum = sum + toNum(s[i]) ;
		if(toNum(s[i])<toNum(s[i+1])){
			sum = sum - 2 * toNum(s[i]) ;
		}
		i++ ;
	}
	return sum ;
}
int main(){
	char s[100] ;
	scanf("%s",s) ;
	int sum = romanToInt(s) ;
	printf("%d\n",sum) ;
	return 0 ;
}  
