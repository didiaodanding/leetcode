struct ListNode{
	int val ; 
	struct ListNode* next ;
}

struct ListNode* deleteDuplicates(struct ListNode* head){
	if(head==NULL){
		return NULL ;
	}
	struct ListNode* temp = head ;
	struct ListNode* ptr = head ;
	struct ListNode* p = head ;	
	while(temp->next!=NULL){
		temp = temp->next ;
		if(temp->val!=ptr->val){
			p->next = temp ;
		}else{
			
		}
		
	}
	return head ;
}
