#include<stdio.h>
#include<malloc.h>
struct TreeNode{
	int val ;
	struct TreeNode* left ;
	struct TreeNode* right ;
} ;

//平衡二叉树
//1、根节点   2、关键字
void insertNode(struct TreeNode** root,int key){
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = key ;
	node->left = NULL ;
	node->right = NULL ;
	struct TreeNode* tempRoot = *root ;//每次都要从根节点进行遍历
	struct TreeNode* parent = NULL ; //保存要插入节点的父亲节点
	while(tempRoot!=NULL){
		parent = tempRoot ;
		if(key==tempRoot->val){
			return ;    //出现了重复，不让插入
		}
		if(key>tempRoot->val){
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

	while(node!=NULL){   //反向更新及平衡节点
		updateHeight(z) ;
		balanceNode(tree,z) ;
		node = node->parent
	}
}
