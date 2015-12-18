#include<stdio.h>
#include<malloc.h>
struct ListNode{
	int val ;
	struct ListNode* next ;	
} ;

struct TreeNode{
	int val ;
	struct TreeNode* left ;
	struct TreeNode* right ;
} ;

void printT(struct TreeNode* root){
	if(root==NULL){

	}else{
		printT(root->left) ;
		printf("%d ",root->val) ;
		printT(root->right) ;
	}
}

struct TreeNode* BST(int* nums,int start,int end){
	if(start>end){
		return NULL ;
	}else{
		int middle = (start+end)/2 ;
		struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode)) ;
		temp->val = nums[middle] ;
		temp->left = BST(nums,start,middle-1) ;
		temp->right = BST(nums,middle+1,end) ;
		return temp ;
	}
}

//已经知道数组的写法了
//将链表变成数组，是最简单的方案
struct TreeNode* sortedListToBST(struct ListNode* head){
	int nums[20000] ;
	int length = 0 ;
	while(head!=NULL){
		nums[length] = head->val ;
		head = head->next ;
		length++ ;
	}
	return BST(nums,0,length-1) ;
}

//输入是  2 3 4 6 7 9 13 15 17 19 20 
//以0结束
int main(){
	int number ;
	struct ListNode* ptr = NULL ;
	struct ListNode* head = NULL ;
	while(scanf("%d",&number)==1&&number){
		if(head==NULL){
			head = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
			head->val = number ;
			head->next = NULL ;
			ptr = head ;
		}else{
			struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode)) ;
			temp->val = number ;
			temp->next = NULL ;
			ptr->next = temp ;
			ptr = temp ;
		}			
	} 
		
	ptr = head ;
	while(ptr!=NULL){
		printf("%d ",ptr->val) ;
		ptr = ptr->next ;
	}
	printf("\n") ; 

	struct TreeNode* root = sortedListToBST(head) ;
	printT(root) ;
	printf("\n") ;
	
	return 0 ;
}
