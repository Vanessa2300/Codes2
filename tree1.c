#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int data;
	struct node *leftChild;
	struct node *rightChild;
};

struct node *root=NULL;

void insert(int data){
	struct node *tempNode= (struct node*)malloc (sizeof(struct node));
	struct node *current;
	struct node *parent;

	tempNode->data = data;
	tempNode->leftChild =NULL;
	tempNode->rightChild=NULL;

	//if tree is empty

	if(root==NULL){
		root = tempNode;
	}else{
		current=root;
		parent=NULL;

		while(1){
			parent =current;

			//go to left of the tree
			if(data < parent->data){
				current = current->leftChild;

				//insert to the left

				if(current ==NULL){
					parent->leftChild=tempNode;
					return;
				}
			}
			//else go to right of the tree
			else{
				current = current->rightChild;

				//insert to the right
				if (current == NULL){
					parent->rightChild = tempNode;
					return;
				}
			}
		}
	}
}

//pre order traversal method

void pre_order_traversal(struct node* root){

	if (root!=NULL){
		printf("%d ",root->data);
		pre_order_traversal(root->leftChild);
		pre_order_traversal(root->rightChild);
	}
}

//in order traversal method

void in_order_traversal(struct node* root){

	if (root!=NULL){

		in_order_traversal(root->leftChild);
		printf("%d ",root->data);
		in_order_traversal(root->rightChild);
	}
}

//post order traversal method

void post_order_traversal(struct node* root){

	if (root!=NULL){

		post_order_traversal(root->leftChild);
		post_order_traversal(root->rightChild);
		printf("%d ",root->data);
	}
}

/*
//Search Method

struct node* search(int data){
	struct node *current =root;
	printf("Visiting elements: ");

	while(current->data !=data){

		if (current!=NULL)
			printf("%d ",current->data);

		//go to left tree
		if(data < current->data){

			current = current->leftChild;
		}

		//else go to right tree
		else{
			current = current->rightChild;
		}

		//not found
		if(current==NULL){
			return NULL;
		}
	}

	return current;
}
*/

int main(){

	int i;
	int n;
	//int array[8] = {45,12,15,55,7,60,25,30};
	int array[50];
	struct node * temp;
	//clrscr();

	printf("Enter number of nodes: ");
	scanf("%d",&n);

	for (i=0;i<n;i++){
	    printf("Enter node element: ");
	    scanf("%d",&array[i]);
	}



	//create tree by inserting data one by one

	for(i=0; i<n ; i++)
		insert(array[i]);



	printf("\nPreorder traversal: ");
	pre_order_traversal(root);

	printf("\nInorder traversal: ");
	in_order_traversal(root);

	printf("\nPostorder traversal: ");
	post_order_traversal(root);

	getch();
	return 0;
}
/*
Enter number of nodes: 8
Enter node element: 45
Enter node element: 12
Enter node element: 15
Enter node element: 55
Enter node element: 7
Enter node element: 60
Enter node element: 25
Enter node element: 30

Preorder traversal: 45 12 7 15 25 30 55 60
Inorder traversal: 7 12 15 25 30 45 55 60
Postorder traversal: 7 30 25 15 12 60 55 45
*/



