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
//传递的是地址
struct TreeNode* ancestor[MAX] ;

//test
struct TreeNode* p_test ;
struct TreeNode* q_test ;

void travel(struct TreeNode* root,struct TreeNode* p ,int* returnSize){
	if(flag==true){
		if(root==NULL){
			return ;
		}else{
			ancestor[*returnSize] = root ;
			if(root==p){
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
	struct TreeNode* ancestorP[MAX] ;
	struct TreeNode* ancestorQ[MAX] ;

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
				return ancestorP[i];
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
		if(ch=='4'){	
			p_test = temp ;
		}

		if(ch=='0'){
			q_test = temp ;
		}

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

//测试用例 356##27##4##10##8##
int main(){
	struct TreeNode* root ;
	root = createTree() ;
	struct TreeNode* result = lowestCommonAncestor(root,p_test,q_test) ;
	printf("%c\n",result->val) ;
	return 0 ;
}
