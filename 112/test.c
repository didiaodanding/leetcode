#include<stdio.h>
#include<stdbool.h>
struct TreeNode{
	int val ;
	struct TreeNode* left ;
	struct TreeNode* right ;
} ;
bool hasPathSum1(struct TreeNode* root,int sum,int result){
	if(result==sum){
		if(root->left==NULL&&root->right==NULL){
			return true ;
		}
	}
	if(root->left!=NULL){
		if(hasPathSum1(root->left,sum,result+root->left->val)){
			return true ;
		}
	}
	if(root->right!=NULL){
		if(hasPathSum1(root->right,sum,result+root->right->val)){
			return true ;
		}
	}
	return false ;
	
}
bool hasPathSum(struct TreeNode* root, int sum) {
	if(root==NULL){
		return false ;
	}
	int result = root->val ;
	if(hasPathSum1(root,sum,result)){
		return true ;
	}else{
		return false ;
	}
}
void createTree(struct TreeNode* root){
	
}
int main(){
	return 0 ;
}
