#include<stdio.h>
#include<malloc.h>
struct ListNode{
	int val ;
	struct ListNode* next ;
};

struct ListNode* reverseList(struct ListNode* head){
	//没有节点
	if(head==NULL){
		return NULL ;
	}
	//一个节点
	if(head->next==NULL){
		return head ;
	}
	//两个节点
	if(head->next->next==NULL){
		head->next->next = head ;
		head = head->next ;
		head->next->next = NULL ;
		return head ;
	}
	//三个以上节点
	struct ListNode* ptr1 = head->next;
	struct ListNode* ptr2 = head->next->next ;
	head->next = NULL ;
	while(ptr2!=NULL){
		ptr1->next = head ;
		head = ptr1 ;
		ptr1 = ptr2 ;
		ptr2 = ptr2->next ;
	}
	ptr1->next = head ;
	return ptr1 ;
}

int main(){
	int num ;
	struct ListNode* head = NULL ;
	struct ListNode* ptr = NULL ;
	while(scanf("%d",&num)&&num){
		if(head==NULL){
			head = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
			head->next = NULL ;
			head->val = num ;
			ptr = head ;
		}else{
			struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
			temp->next = NULL ;
			temp->val = num ;
			ptr->next = temp ;
			ptr = temp  ;
		}
	}
	ptr = head ;
	while(ptr!=NULL){
		printf("%d ",ptr->val) ;
		ptr = ptr->next ;
	}
	printf("\n") ;
	ptr = reverseList(head) ;
	while(ptr!=NULL){
		printf("%d ",ptr->val) ;
		ptr = ptr->next ;
	}
	printf("\n") ;
	return 0 ;
}
