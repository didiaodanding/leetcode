#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
struct TreeNode{
	int val ;
	struct TreeNode* left ;
	struct TreeNode* right ;
};

struct queue{
	int front ;
	int rear ;
	struct TreeNode* element[1000] ;
};

void enqueue(struct queue* q,struct TreeNode* node){
	q->element[q->rear] = node ;
	(q->rear)++ ;
} 

struct TreeNode* dequeue(struct queue* q){
	struct TreeNode* node = q->element[q->front] ;
	(q->front)++ ;
	return node ;
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

bool isSymm(int* array,int length){
	int i=0 ;
	length = length-1 ;
	while(i<=length){
		if(array[i]==array[length]){
			i++ ;
			length-- ;
		}else{
			return false ;
		}
	}
	return true ;
}

bool isSymmetric(struct TreeNode* root){
	int array[1000] ;
	if(root==NULL){
		return true;
	}else{
		struct queue q ;
		q.front = 0 ;
		q.rear = 0 ;
		enqueue(&q,root) ;
		while(!empty(&q)){
			int length = size(&q) ;
			int le = 0 ;
			for(int i=0;i<length;i++){
				struct TreeNode* temp = dequeue(&q) ;
				if(temp->left!=NULL){
					array[le] = temp->left->val ;
					enqueue(&q,temp->left) ;
					le++ ;
				}else{
					array[le] = -1 ;
					le++ ;
				}
				if(temp->right!=NULL){
					array[le] = temp->right->val ;
					enqueue(&q,temp->right) ;
					le++ ;
				}else{
					array[le] = -1 ;
					le++ ;
				}
			}
			if(isSymm(array,le)){
				
			}else{
				return false ;
			}
		}
		return true ;
	} 
}

void printT(struct TreeNode* root){
        if(root==NULL){
                return ;
        }else{
                struct queue q ; 
		q.front = 0 ;
		q.rear = 0 ;
                enqueue(&q,root) ;
                while(!empty(&q)){
               		struct TreeNode* temp = dequeue(&q) ;
			printf("%c ",(char)temp->val) ;
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
	struct TreeNode* root ;
	root = createTree() ;
	if(isSymmetric(root)){
		printf("is Symmetric\n") ;
	}else{
		printf("is not Symmetric\n") ;
	}
//	printT(root) ;
	return 0 ;
}

