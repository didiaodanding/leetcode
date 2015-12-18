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

struct TreeNode* travel(int* inorder,int inLeft,int inRight,int* postorder,int postLeft,int postRight){
	if(inLeft>inRight){
		return NULL ;
	}
	int location = find(inorder,inLeft,inRight,postorder[postRight]) ;
        struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode)) ;
        temp->val = postorder[postRight] ;
//        temp->left = travel(preorder,preLeft+1,preLeft+(location-inLeft),inorder,inLeft,location-1) ;
	temp->left = travel(inorder,inLeft,location-1,postorder,postLeft,postLeft+location-inLeft-1) ;
//	temp->right = travel(preorder,preRight-(inRight-location)+1,preRight,inorder,location+1,inRight) ;
	temp->right = travel(inorder,location+1,inRight,postorder,postRight-(inRight-location),postRight-1) ;
	return temp ;
		
}
//中序遍历 12453687
//后序遍历  42516873
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	return travel(inorder,0,inorderSize-1,postorder,0,postorderSize-1) ;
} 

void printT(struct TreeNode* root){
	if(root==NULL){

	}else{
		printT(root->left) ;
		printT(root->right) ;
		printf("%d ",root->val) ;
	}
}
int main(){
	int inorder[] = {1,2,4,5,3,6,8,7} ;
	int postorder[] = {4,2,5,1,6,8,7,3} ;
	struct TreeNode* root = buildTree(inorder,8,postorder,8) ;
	printT(root) ;
	return 0 ;
}
