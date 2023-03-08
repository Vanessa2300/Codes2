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

//in order traversal method

void in_order_traversal(struct node* root){
	
	if (root!=NULL){
		
		in_order_traversal(root->leftChild);
		printf("%d ",root->data);
		in_order_traversal(root->rightChild);
	}
}


//height of tree
int height(struct node* root){
    int lheight, rheight;
    if (root==NULL)
        return -1;
    else{
        
        lheight = height(root->leftChild);
        rheight = height(root->rightChild);
            if(lheight>rheight)
                return lheight+1;
            else
                return rheight+1;
    }
}


//mirror
void mirror(struct node* root){
    struct node *temp;
    if(root!=NULL){

    temp=root->leftChild;
    root->leftChild = root->rightChild;
    root->rightChild = temp;
    mirror(root->leftChild);
    printf("%d ",root->data);
    mirror(root->rightChild);
    }
    //return root;
    
}

//Mirror tree Level wise tree
void mirrorLevel(struct node* root, int currentLevel, int level) {
   
  if(root == NULL) {
      return;   
  }  
  if(currentLevel == level) {
      printf(" %d ", root->data);
      return;
  }
              
  mirrorLevel(root->leftChild, currentLevel+1, level);
  mirrorLevel(root->rightChild, currentLevel+1, level);
}

void mirrorlevelwise(struct node* root){
    /* Find the height of tree */
    int i, h = height(root);
    /* Iterate from level 0 to height-1 and 
 print one level at a time */
    for(i = 0; i <= h; i++){
     mirrorLevel(root, 0, i);
     printf("\n");
    }
}


//Original Tree level Wise
void printNodesAtLevel(struct node* root, int currentLevel, int level) {
   
  if(root == NULL) {
      return;   
  }  
  if(currentLevel == level) {
      printf(" %d ", root->data);
      return;
  }
              
  printNodesAtLevel(root->rightChild, currentLevel+1, level);
  printNodesAtLevel(root->leftChild, currentLevel+1, level);
}




/* Printed nodes of binary tree level wise */
void levelwise(struct node* root){
    /* Find the height of tree */
    int i, h = height(root);
    /* Iterate from level 0 to height-1 and 
 print one level at a time */
    for(i = 0; i <= h; i++){
     printNodesAtLevel(root, 0, i);
     printf("\n");
    }
}

//Print leaf nodes
void printLeafNodes(struct node* root){
    if (root==NULL)
        return ;
        
    if (root->leftChild==NULL && root->rightChild==NULL){
        printf("%d ",root->data);
        return;
    }
    
    if(root->leftChild)
        printLeafNodes(root->leftChild);
        
    if(root->rightChild)
        printLeafNodes(root->rightChild);
    
}

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
	
	printf("\n===============================================");
	printf("\nOriginal Tree ");
	in_order_traversal(root);
	printf("\n===============================================");
	
		
	printf("\n===============================================");
	printf("\nHeight of tree: %d",height(root));
	printf("\n===============================================");
		
	printf("\n===============================================");
	printf("\nLeaf Nodes: \n");
	printLeafNodes(root);
	printf("\n===============================================");

	
	printf("\n===============================================");
	printf("\nMirror Tree: ");
	mirror(root);
	printf("\n===============================================");
	
	printf("\n===============================================");
	printf("\nOriginal Tree Level Wise:\n");
	levelwise(root);
	printf("\n===============================================");
	
	printf("\n===============================================");
	printf("\nMirror Image of Tree Level Wise:\n");
	mirrorlevelwise(root);
	printf("\n===============================================");

	
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

===============================================
Original Tree 7 12 15 25 30 45 55 60 
===============================================
===============================================
Height of tree: 4
===============================================
===============================================
Leaf Nodes: 
7 30 60 
===============================================
===============================================
Mirror Tree: 60 55 45 30 25 15 12 7 
===============================================
===============================================
Original Tree Level Wise:
 45 
 12  55 
 7  15  60 
 25 
 30 

===============================================
===============================================
Mirror Image of Tree Level Wise:
 45 
 55  12 
 60  15  7 
 25 
 30 

===============================================
*/

