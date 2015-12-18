#include<stdio.h>
#include<stdbool.h>
struct ListNode{
	int val ;
	struct ListNode* next ;
} ;

int getLength(struct ListNode* head){
	int count = 0 ;	
	while(head!=NULL){
		count++ ;
		head = head->next ;
	}
	return count ;
}

bool isPalind(int array[],int length){
	int end = length -1 ;
	for(int i=0;i<length;i++){
		if(array[i] == array[end]){
			end-- ;
		}else{
			return false ;
		}
	}

	return true ;
}


bool isPalindrome(struct ListNode* head){
	int length = getLength(head) ;
	int array[length] ;
	for(int i=0;i<length;i++){
		array[i] = head->val ;
		head = head->next ;
	}

	return isPalind(array,length) ;
}

int main(void){
	return 0 ;
}
