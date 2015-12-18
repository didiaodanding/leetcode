#include<stdio.h>
#include<malloc.h>
struct ListNode{
	int val ;
	struct ListNode *next ;
} ;
struct ListNode* removeElements(struct ListNode* head,int val){
	if(head==NULL)
		return NULL ;
	while(head->val==val){
		if(head->next!=NULL){
			head = head->next ;
		}else{
			return NULL ;
		}
	}
	struct ListNode* ptr = head ;
	while(ptr->next!=NULL){
		if(ptr->next->val==val){
			if(ptr->next->next!=NULL){
				ptr->next = ptr->next->next ;
			}else{
				ptr->next = NULL ;
			}
		}else{
			ptr = ptr->next ;
		}
	}
	return head ;
}

int main(){
	struct ListNode *head = NULL;
	head = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
	head->next = NULL ;
	head->val = 1 ;
	int num ;
	while(1==scanf("%d",&num)&&num){
		struct ListNode *ptr = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
		ptr->val = num ;
		ptr->next = head->next ;
		head->next = ptr ;
		
		
	}
	head = removeElements(head,6) ;
	while(head->next!=NULL){
		printf("%d ",head->val) ;
		head = head->next ;
	}
	printf("%d ",head->val) ;
	printf("\n") ;
	return 0 ;
}
