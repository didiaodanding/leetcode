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
//二叉排序树插入需要知道的信息
//1、根节点    2、关键字
void insertNode(struct TreeNode** root , int key){
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode)) ; //开辟节点，等待插入
	node->val = key ;
	node->left = NULL ;
	node->right = NULL ;
	struct TreeNode* tempRoot = *root ;   //每次都要从根节点进行遍历
	struct TreeNode* parent = NULL ;  //保存要插入节点的父亲节点
	while(tempRoot!=NULL){
		parent = tempRoot ;
		if(key==tempRoot->val){
			return ;             //出现了重复，不让插入
		}if(key>tempRoot->val){
			tempRoot = tempRoot->right ;
		}else{
			tempRoot = tempRoot->left ;
		}
	}

	if(*root==NULL){
		*root = node ;
	}else if(key>parent->val){
		parent->right = node ;
	}else{
		parent->left = node ;
	}
}

int main(){
	struct TreeNode* bst = NULL ;
	int array[] = {15,6,18,3,7,17,20,2,4,13,9} ;
	for(int i=0;i<11;i++){
		insertNode(&bst,array[i]) ;
	}
	
	printT(bst) ;
	printf("\n") ;
	return 0 ;
}
