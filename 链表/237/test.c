#include<malloc.h>
#include<stdio.h>
struct ListNode{
	int val ;
	struct ListNode* next ;	
} ;

void deleteNode(struct ListNode* node){
	if(node==NULL){
		return ;
	}

	node->val = node->next->val ;
	node->next = node->next->next ;
}


void addNode(struct ListNode* head,int number){
	struct ListNode* ptr = head ;
	while(ptr->next!=NULL){
		ptr = ptr->next ;
	}
	
	struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
	temp->next = NULL ;
	temp->val = number ;
	ptr->next = temp ;
	head = NULL ;
	
}

int main(void){
	int number ;
	struct ListNode* head = NULL ;
	while((1==scanf("%d",&number))&&number){
		if(head==NULL){
			head = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
			head->val = number ;
			head->next = NULL ;
		}else{
			addNode(head,number) ;
		}		
	}
	while(head!=NULL){
		printf("%d ",head->val) ;	
		head = head->next ;
	}
	printf("\n") ;
	return 0 ;
}
