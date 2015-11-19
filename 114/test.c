#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct TreeNode{
	int val ;
	struct TreeNode* left ;
	struct TreeNode* right ;
} ;

#define MAX 5000 
int array[MAX] ;
int index = 0 ;
void flatten1(struct TreeNode* root){
	if(root==NULL){
		return ;
	}else{
		array[index++] = root->val ;
		flatten1(root->left) ;
		flatten1(root->right) ;
	}

}
void flatten(struct TreeNode* root){
	if(root==NULL){
		return ;
	}
	memset(array,MAX,sizeof(int)) ;
	index = 0 ;
	flatten1(root) ;
	struct TreeNode* ptr = root ;
	int i = 0 ;
	root->val = array[i++] ;
	root->left = NULL ;
	root->right = NULL ;
	while(i<index){
		struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode)) ;
		temp->val = array[i++] ;
		temp->left = NULL ;
		temp->right = NULL ;
		ptr->right = temp ;
		ptr = temp  ;
	} 
	
}

int main(){
	return 0 ;
}
