#include<stdio.h>
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
   int result = 0 ;
    int right = G ;
    if(C<G)
        right = C ;
    int left = E ;
    if(A>E)
        left = A ;
    int top = H ;
    if(D<H)
        top = D ;
    int bottom = F ;
    if(B>F)
        bottom = B ;
    
   if(top>bottom&&right>left){
	result = (top-bottom)*(right-left) ;
   }else{
   }
    return (H-F)*(G-E)+(D-B)*(C-A)-result ;
}
int main(void){
	int result = computeArea(-1500000001,0,-1500000000,1,1500000000,0,1500000001,1) ;
	printf("%d\n",result) ;
	return 0 ;
}
