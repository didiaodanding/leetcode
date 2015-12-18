#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
struct TreeNode{
	int val ;
	struct TreeNode* left ;
	struct TreeNode* right ;
} ;

//队列
struct queue{
	struct TreeNode* element[100] ;
	int front,rear ;
};

//不考虑循环队列
void enqueue(struct queue* q,struct TreeNode* tn){
	q->rear = q->rear+1 ;
	q->element[q->rear] = tn ;
}
//不考虑循环队列
struct TreeNode* dequeue(struct queue* q){
	q->front = q->front+1 ;
	struct TreeNode* tn  = q->element[q->front] ;
	return tn ;	

}

bool empty(struct queue* q){
	return q->front==q->rear ;
}

int size(struct queue* q){
	return q->rear - q->front ;
}
//层序遍历
void printT(struct TreeNode* root){
	struct queue q ;
	q.front = 0 ;
	q.rear = 0 ;
	if(root==NULL){
		return ;
	}else{
		enqueue(&q,root) ;
		while(!empty(&q)){
			struct TreeNode* tn = dequeue(&q) ;
			printf("%d ",tn->val-'0') ;
			if(tn->left!=NULL){
				enqueue(&q,tn->left) ;
			}
			if(tn->right!=NULL){
				enqueue(&q,tn->right) ;
			}
		}
	}
}

int* rightSideView(struct TreeNode* root,int* returnSize){
	 struct queue q ;
        q.front = 0 ;
        q.rear = 0 ;
	int* result = (int*)malloc(sizeof(int)*100) ;
        if(root==NULL){
                return NULL ;
        }else{
                enqueue(&q,root) ;
                while(!empty(&q)){
			int length = size(&q) ;
			for(int i=0;i<length;i++){
				struct TreeNode* tn = dequeue(&q) ;
                        	if(i==0){
					result[*returnSize] = tn->val ;
					(*returnSize)++ ;
				}
				if(tn->right!=NULL){
                        	        enqueue(&q,tn->right) ;
                	        }
                        	if(tn->left!=NULL){
                                	enqueue(&q,tn->left) ;
                        	}
			}
                }
        }
	return result ;
	
}

struct TreeNode* createTree(){
	int ch ;
	ch = getchar() ;
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

void printTree(struct TreeNode* root){
	if(root==NULL){
		return ;
	}else{
		printf("%d ",root->val-'0') ;
		printTree(root->left) ;
		printTree(root->right) ;
	}
}
int main(){
	struct TreeNode* root ;
	root = createTree() ;
	printTree(root) ;
	printf("\n") ;
	printT(root) ;
	printf("\n") ;
	int returnSize = 0 ;
	int* result = rightSideView(root,&returnSize);
	for(int i=0;i<returnSize ;i++){
		printf("%d ",result[i]) ;
	}
	printf("\n") ;
	return 0 ;
}
