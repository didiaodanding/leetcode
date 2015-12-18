#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
struct TreeNode{
	int val ;
	struct TreeNode* left ;
	struct TreeNode* right ;
} ;
 struct queue{
        int front ;
        int rear ;
        struct TreeNode *element[3000] ;
} ;

void enqueue(struct queue* q, struct TreeNode* node){
        q->element[q->rear] = node ;
        (q->rear)++ ;
}

struct TreeNode* dequeue(struct queue* q){
        struct TreeNode* temp = q->element[q->front] ;
        (q->front)++ ;
        return temp ;
}

bool empty(struct queue* q){
        if(q->rear-q->front==0){
                return true ;
        }else{
                return false ;
        }
}

int size(struct queue* q){
        return q->rear-q->front ;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    *returnSize = 0 ;
    *columnSizes = (int*)malloc(sizeof(int)*3000) ;
    if(root==NULL){
                return NULL ;
        }else{
                int** result = (int**)malloc(3000*sizeof(int*)) ;
                struct queue q  ;
                q.front = 0 ;
                q.rear = 0 ;
                enqueue(&q,root) ;
                while(!empty(&q)){
                        int length = size(&q) ;

                        int* resu = (int*)malloc(length*sizeof(int)) ;
                        (*columnSizes)[*returnSize] = length ;
                        for(int i=0;i<length;i++){
                                struct TreeNode* temp = dequeue(&q) ;
                                resu[i] = temp->val ;
                                if(temp->left!=NULL){
                                        enqueue(&q,temp->left) ;
                                }
                                if(temp->right!=NULL){
                                        enqueue(&q,temp->right) ;
                                 }
                        }

                        result[*returnSize] = resu ;
                        (*returnSize)++ ;
                }
		

		int i = 0 ;
		int len = *returnSize-1 ;
		while(i<len){
			int* ptr = result[i] ;
			int tempColumnSizes = (*columnSizes)[i] ;

			result[i] = result[len] ;
			(*columnSizes)[i] = (*columnSizes)[len] ;

			result[len] = ptr ;
			(*columnSizes)[len] = tempColumnSizes ;

			i++ ;
			len-- ; 
		}
                return result ;
        }


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
		struct queue q ;
		q.front = 0 ;
		q.rear = 0 ;
		enqueue(&q,root) ;
		while(!empty(&q)){
			struct TreeNode* temp = dequeue(&q) ;
			printf("%c",(char)temp->val) ;
			if(temp->left!=NULL){
				enqueue(&q,temp->left) ;
			}
			if(temp->right!=NULL){
				enqueue(&q,temp->right) ;
			}
		}	
	}
}

int main(){
	int *columnSizes ;
	int returnSize ;
	struct TreeNode* root = createTree() ;
	int** result = levelOrder(root,&columnSizes,&returnSize) ;
	for(int i=0;i<returnSize;i++){
		for(int j=0;j<columnSizes[i];j++){
			printf("%c",(char)result[i][j]) ;
		}
		printf("\n") ;
	}
//	printT(root) ;
	return 0 ;
}
