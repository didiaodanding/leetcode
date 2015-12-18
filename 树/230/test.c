#include<stdbool.h>
#include<stdio.h>
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
bool flag = true ;
int result ;
int count = 0 ;
//中序遍历，将结果保存到result中，递归到第ｋ个值即停止递归
void travel(struct TreeNode* root,int k){
	if(flag==true){
		if(root==NULL){
			return ;
		}else{
			travel(root->left,k) ;
			count++ ;
			if(count==k){
				result = root->val ;
				flag = false ;
				return ;
			}
			travel(root->right,k) ;
		}
	}
}

int kthSmallest(struct TreeNode* root, int k) {
    flag = true ;
    count =  0 ;
    travel(root,k) ;
    return result ;
}

int main(void){
	return 0 ;
}
