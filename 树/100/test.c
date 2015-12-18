#include<stdbool.h>
#include<malloc.h>
struct TreeNode{
	int val ;
	struct TreeNode* left ;
	struct TreeNode* right ;
} ;
bool isSameTree(struct TreeNode* p,struct TreeNode* q){
	if(p==NULL&&q==NULL){
		return true ;
	}else if(p==NULL&&q!=NULL){
		return false ;
	}else if(p!=NULL&&q==NULL){
		return false ;
	}else{
		if(p->val==q->val){
			if(isSameTree(p->left,q->left)){
				
			}else{
				return false ;
			}
			if(isSameTree(p->right,q->right)){

			}else{
				return false ;
			}
		}else{
			return false ;
		}
	}
	return true ;
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

void printT(struct TreeNode* root){
	if(root==NULL){
		
	}else{
		printf("%c ",(char)root->val) ;
		printT(root->left) ;
		printT(root->right) ;
	}
}

int main(){
	struct TreeNode* root1 ;
	struct TreeNode* root2 ;
	root1 = createTree() ;
	getchar() ;
	root2 = createTree() ;
	printT(root1) ;
	printf("\n") ;
	printT(root2) ;
	printf("\n") ;
	if(isSameTree(root1,root2)){
		printf("is same\n") ;
	}else{
		printf("is different\n") ;
	}
	return 0 ;
}
