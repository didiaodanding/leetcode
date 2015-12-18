#include<stdio.h>
#include<malloc.h>
struct TreeNode{
	int val ;
	struct TreeNode* left ;
	struct TreeNode* right ;
} ;


int find(int* inorder,int inLeft,int inRight,int head){
	for(int i=inLeft;i<=inRight;i++){
		if(inorder[i]==head){
			return i ;
		}
	}
	
}

struct TreeNode* travel(int* preorder,int preLeft,int preRight,int* inorder,int inLeft,int inRight){
	if(inLeft>inRight){
		return NULL ;
	}
	int location = find(inorder,inLeft,inRight,preorder[preLeft]) ;
        struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode)) ;
        temp->val = preorder[preLeft] ;
        temp->left = travel(preorder,preLeft+1,preLeft+(location-inLeft),inorder,inLeft,location-1) ;
	temp->right = travel(preorder,preRight-(inRight-location)+1,preRight,inorder,location+1,inRight) ;
	return temp ;
		
}
//先序遍历 12453687
//中序遍历  42516873
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	return travel(preorder,0,preorderSize-1,inorder,0,inorderSize-1) ;
} 

void printT(struct TreeNode* root){
	if(root==NULL){

	}else{
		printf("%d ",root->val) ;
		printT(root->left) ;
		printT(root->right) ;
	}
}
int main(){
	int preorder[] = {1,2,4,5,3,6,8,7} ;
	int inorder[] = {4,2,5,1,6,8,7,3} ;
	struct TreeNode* root = buildTree(preorder,8,inorder,8) ;
	printT(root) ;
	return 0 ;
}
