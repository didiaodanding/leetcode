#include<stdio.h>
#include<malloc.h>
struct TreeNode{
	int val ;
	struct TreeNode* left ;
	struct TreeNode* right ;
} ;

int dept = 10000 ;

void printT(struct TreeNode* root){
	if(root==NULL){

	}else{
		printf("%c ",(char)root->val) ;
		printT(root->left) ;
		printT(root->right) ;
	}
}

void minDepthTree(struct TreeNode* root,int depth){
	if(root==NULL){
	
	}else{
		minDepthTree(root->left,depth+1) ;
		minDepthTree(root->right,depth+1) ;
		if(root->left==NULL&&root->right==NULL){
			if(depth<dept){
                        	dept = depth ;
                	}
		}
	} 
}

int minDepth(struct TreeNode* root){
	if(root==NULL){
		return 0 ;
	}
	dept = 10000 ;
	minDepthTree(root,1) ;
	return dept ;
}

struct TreeNode* createTree(){
	char ch = getchar() ;
	if(ch=='#'){
		return NULL ;
	}else{
		struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode)) ;
		temp->val = ch ;
		temp->left = createTree() ;
		temp->right = createTree() ;
		return temp ;
	}
}

int main(){
	struct TreeNode* root = createTree() ;
	int length = minDepth(root) ;
	printf("%d\n",length) ;
//	printT(root) ;
	return 0 ;
	
}
