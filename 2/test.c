#include<stdio.h>
#include<malloc.h>
struct ListNode{
	int val ;
	struct ListNode *next ;
} ;
struct ListNode* reverse(struct ListNode** head){
	struct ListNode* ptr1 ;
	struct ListNode* ptr2 ;
	if((*head)->next==NULL){
		return *head ;
	}
	if((*head)->next->next==NULL){
		ptr1 = (*head)->next ;
		ptr1->next = *head ;
		(*head)->next = NULL ;
		return ptr1 ;
	}
	ptr1 = (*head)->next ;
	ptr2 = (*head)->next->next;
	(*head)->next = NULL ;
	while(*head!=ptr1){
		ptr1->next = *head ;
		*head = ptr1 ;
		ptr1  = ptr2 ;
		if(ptr2->next!=NULL){
			ptr2 = ptr2->next ;
		}
	}
	return *head ;
}

void calc(int num,int* r1,int* r2){
	*r1 = num/10 ;
	*r2 = num%10 ;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* returnNode = NULL ;
	struct ListNode* temp = NULL ;
	while(l1!=NULL||l2!=NULL){
		if(returnNode==NULL){
			returnNode = (struct ListNode*)malloc(sizeof(struct ListNode));
			returnNode->next = NULL ;
			if(l1!=NULL&&l2!=NULL){
				returnNode->val = l1->val + l2->val ;
			}else if(l1!=NULL&&l2==NULL){
				returnNode->val = l1->val  ;
			}else if(l1==NULL&&l2!=NULL){
				returnNode->val = l2->val ;	
			}
			temp = returnNode ;
		}else{
			struct ListNode* ptr = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
			if(l1!=NULL&&l2!=NULL){
				ptr->val = l1->val + l2->val ;
			}else if(l1!=NULL&&l2==NULL){
				ptr->val = l1->val  ;
			}else if(l1==NULL&&l2!=NULL){
				ptr->val = l2->val ;	
			}
			temp->next=ptr ;
			ptr->next = NULL ;
			temp = ptr ;
		}
		if(l1!=NULL){
			l1 = l1->next ;
		}
		if(l2!=NULL){
			l2 = l2->next ;
		}
	}
//	returnNode = reverse(&returnNode) ;
	temp = returnNode ;
	int r1 = 0 ;
	int r2 = 0 ;
	while(temp!=NULL){
		temp->val = temp->val + r1 ;
		calc(temp->val,&r1,&r2) ;
		temp->val = r2 ;
		temp = temp->next ;
	}
	temp = returnNode ;
	while(temp->next!=NULL){
		temp = temp->next ;
	}
	if(r1!=0){
		struct ListNode* temp1 = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
		temp1->next = NULL ;
		temp1->val = r1 ;
		temp->next = temp1 ;
		temp = temp1 ;
	}
	return returnNode  ; 
}

int main(){
	int number ;
	struct ListNode* head = NULL ;
	struct ListNode* head2 = NULL ;
	while(scanf("%d",&number)&&number!=0){
		if(head==NULL){
			head = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
			head->val = number ;
			head->next = NULL ;
		}else{
			struct ListNode* ptr = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
			ptr->val = number ;
			ptr->next = head->next ;
			head->next = ptr ;
		}
	}
	
	while(scanf("%d",&number)&&number!=0){
		if(head2==NULL){
			head2 = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
			head2->val = number ;
			head2->next = NULL ;
		}else{
			struct ListNode* ptr = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
			ptr->val = number ;
			ptr->next = head2->next ;
			head2->next = ptr ;
		}
	}
	struct ListNode* returnNode = addTwoNumbers(head,head2) ;
	while(returnNode!=NULL){
		printf("%d ",returnNode->val) ;
		returnNode = returnNode->next ;
	}
	printf("\n") ;
//	while(head2!=NULL){
//		printf("%d ",head2->val) ;
//		head2 = head2->next ;
//	}
//	printf("\n") ;
	return 0 ;
}
