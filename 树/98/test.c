#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
struct TreeNode{
	int val ;
	struct TreeNode* left ;
	struct TreeNode* right ;
} ;

int lastVal ;  //最小值  保持最后一个值
int firstNode ;


//中序遍历平衡二叉树，按升序排列
bool isValidBSTTree(struct TreeNode* root){
	if(root==NULL){
                return true ;
        }else{
                if(isValidBSTTree(root->left)){

                }else{
                        return false ;
                }

                if(lastVal<root->val){

                }else{
			if(firstNode==false){
				return false ;
			}
                }

               	lastVal = root->val ;
		firstNode = false ;

                if(isValidBSTTree(root->right)){

                }else{
                        return false ;
                }

                return true ;
        }

}

bool isValidBST(struct TreeNode* root){
	unsigned long length = sizeof(int) ;
	firstNode = true ;
	if(length==4){
		lastVal = 0x80000001-1 ;  //取int最小值
	}
	if(length==8){
//		lastVal = 0x8000000000000001-1 ;
	}
	return isValidBSTTree(root) ;
}


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
	int array[] = {1,1} ;
	for(int i=0;i<2;i++){
		insertNode(&bst,array[i]) ;
	}
	
	printT(bst) ;
	printf("\n") ;
	if(isValidBST(bst)){
		printf("it is a BST tree\n") ; 
	}else{
		printf("it is not a BST tree\n") ;
	}
	return 0 ;
}
