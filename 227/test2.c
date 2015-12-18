#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool isoperation(char symbol){
        if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'){
                return true ;
        }
        return false ;
}
int calculate(char* s){
	int sum = 0 ;
	int prenumber = 0 ;
	int length = strlen(s) ;
	char flag = '+' ;
	if(length<1){
		return 0 ;
	}
        for(int i=0;i<length;){
                if(isoperation(s[i])){
                        flag = s[i] ;
                        i++ ;
                }else if(s[i]==' '){
			i++ ;
		}else{
                        int number = 0 ;
                        while(i<length&&s[i]<='9'&&s[i]>='0'){
                                number = number*10+(s[i]-'0') ;
                                i++ ;
                        }
                        if(flag=='+'){
                                sum += number ;
				prenumber  = number ;
                        }
                        if(flag=='-'){
                                sum  -= number ;
				prenumber = -number ;
                        }
                        if(flag=='*'){
				if(prenumber<0){
                                	sum = sum - prenumber + prenumber*number ;
				}else{
					sum = sum - prenumber + prenumber*number ;
				}
				prenumber = prenumber * number ;
                        }
                        if(flag=='/'){
				 if(prenumber<0){
                                        sum = sum - prenumber + prenumber/number ;
                                }else{
                                        sum = sum - prenumber + prenumber/number ;
                                }
				prenumber = prenumber / number ;

                        }
                }
        }

        return sum ;

}
int main(){
	 char *s = "   1+  7   -   7  *3 /3   +  6- 3 +1 -8-2    " ;
        int result = calculate(s) ;
        printf("%d\n",result) ;
        return 0 ;

}
