#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX 30000 
bool isoperation(char symbol){
        if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'|| symbol==' '){
                return true ;
        }
        return false ;
}
int calculate(char* s){
        int array[MAX] ;
        int index = 0 ;
        for(int i=0;i<strlen(s);){
                while(s[i]==' '){
                        i++ ;
                }
                char flag = '+' ;
                if(!isoperation(s[i])){
                        flag = '+' ;
                }else{
                        flag = s[i] ;
                        i++ ;
                }
                while(s[i]==' '){
                        i++ ;
                }
                if(!isoperation(s[i])&&i<strlen(s)){
                        int number = 0 ;
                        while(i<strlen(s)&&!isoperation(s[i])){
                                number = number*10+(s[i]-'0') ;
                                i++ ;
                        }
                        if(flag=='+'){
                                array[index++] = number ;
                        }
                        if(flag=='-'){
                                array[index++] = -number ;
                        }
                        if(flag=='*'){
                                array[index-1] = array[index-1]*number ;
                        }
                        if(flag=='/'){
                                array[index-1] = array[index-1]/number ;
                        }
                }
        }
        int sum = 0 ;
        for(int i=0;i<index;i++){
                sum = sum + array[i] ;
        }

        return sum ;

}
int main(){
	 char *s = "1+7-7+3+3+6-3+1-8-2" ;
        int result = calculate(s) ;
        printf("%d\n",result) ;
        return 0 ;

}
