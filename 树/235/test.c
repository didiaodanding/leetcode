#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
struct TreeNode{
	int val ;
	struct TreeNode* left ;
	struct TreeNode* right ;
};
#define MAX 100 
bool flag = true  ;
int ancestor[MAX] ;

void travel(struct TreeNode* root,struct TreeNode* p ,int* returnSize){
	if(flag==true){
		if(root==NULL){
			return ;
		}else{
			ancestor[*returnSize] = root->val ;
			if(root->val==p->val){
				flag = false ;
				return ;
			}
			
			*returnSize = *returnSize + 1 ;	
			travel(root->left,p,returnSize) ;
			travel(root->right,p,returnSize) ;
			if(flag==true){
				*returnSize = *returnSize - 1 ;
			}	
		}
	}	
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	int ancestorP[MAX],ancestorQ[MAX] ;

	int countP = 0 ;
	int countQ = 0 ;

	flag = true ;
	travel(root,p,&countP) ; 
	for(int i=0;i<=countP;i++){
		ancestorP[i] = ancestor[i] ;
	} 

	flag = true ;

	travel(root,q,&countQ) ;
	for(int i=0;i<=countQ;i++){
		ancestorQ[i] = ancestor[i] ;
	}
	
	for(int i=countP;i>=0;i--){
		for(int j=countQ;j>=0;j--){
			if(ancestorP[i]==ancestorQ[j]){
				struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode)) ;
				temp->val = ancestorP[i] ;
				temp->right = NULL ;
				temp->left = NULL ;
				return temp ;
			}
		}
		
	}
	return NULL ;
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
	struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode)) ;
	p->left = NULL ;
	p->right = NULL ;
	p->val = '8' ;
	struct TreeNode* q = (struct TreeNode*)malloc(sizeof(struct TreeNode)) ;
	q->left = NULL ;
	q->right= NULL ;
	q->val = '1' ;
	lowestCommonAncestor(root,p,q) ;
	struct TreeNode* result = lowestCommonAncestor(root,p,q) ;
	printf("%c\n",result->val) ;
	return 0 ;
}
