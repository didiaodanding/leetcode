#include<stdio.h>
#include<malloc.h>
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

struct TreeNode* sortedArrayToBST(int* nums,int numsSize){
	return BST(nums,0,numsSize-1) ;
}

int main(){
	int array[] = {2,3,4,6,7,9,13,15,17,18,20} ;
	struct TreeNode* root = sortedArrayToBST(array,11) ;
	printT(root) ;
	printf("\n") ;
	return 0 ;
}
