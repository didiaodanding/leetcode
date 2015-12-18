#include<stdio.h>
#include<malloc.h>
int maxlength = 0 ;
struct TreeNode{
	int val ;
	struct TreeNode* left ;
	struct TreeNode* right ;
};

void comlen(struct TreeNode* root ,int length){
	if(root==NULL){
		return ;
	}else{
		if(length>maxlength){
			maxlength = length ;
		}
		comlen(root->left,length+1) ;
		comlen(root->right,length+1) ;
	}
}

int maxDepth(struct TreeNode* root){
	comlen(root,1) ;
	return maxlength ;
}

struct TreeNode* createTree(){
	char ch = getchar() ;
	struct TreeNode* temp ;
	if(ch=='#'){
		return NULL ;
	}else{
		temp = (struct TreeNode*)malloc(sizeof(struct TreeNode)) ;
		temp->val = ch ;
		temp->left = createTree() ;
		temp->right = createTree() ;
	}
	return temp ;
	
}

void printT(struct TreeNode* root){
	if(root==NULL){
		return ;
	}else{
		printf("%c ",(char)root->val) ;
		printT(root->left) ;
		printT(root->right) ;
	}	
}

int main(){
	struct TreeNode* root ;
	root = createTree() ;
	//printT(root) ;
	int length = maxDepth(root) ;
	printf("%d\n",length) ;
	return 0 ;
}
