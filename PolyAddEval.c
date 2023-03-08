#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node
{ int deg,coef;
 struct Node *next;

}*head=NULL, *end;

struct Node *newNode, *temp;

void create(){
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter degree: ");
	scanf("%d",&temp->deg);
	printf("Enter coefficient: ");
	scanf("%d",&temp->coef);

	if(head==NULL){
		head=temp;
		end=temp;
	}
	else{
		end->next=temp;
		end=temp;
	}
}

void display(){
	struct Node *temp;
	temp=head;
	while (temp!=NULL){
		printf("%dx^%d + ",temp->coef,temp->deg);
		temp = temp->next;
	}
}

void evaluate(){
    struct Node *temp;
    int x, sum=0, power,i;
    printf("\nEnter value of variable x: ");
    scanf("%d",&x);
	temp=head;
	
	while (temp!=NULL){
	    power=1;
		for (i=1;i<=temp->deg;i++){
		   power = power * x;
		}
		
	   sum = sum + temp->coef * power;
	   temp=temp->next;
	}
	
	printf("\nEvaluation of polynomial = ");
	printf("%d",sum);
}

//Poly add

struct Node *create_add(struct Node *head)
{
int i,n;
    printf("\nEnter no. of terms: ");
    scanf("%d",&n);
    printf("\nEnter the terms in descending order of degree\n");
        for(i=0;i<n;i++)
        {
                newNode=(struct Node *)malloc(sizeof(struct Node));
                newNode->next=NULL;
                printf("coefficient: ");
                scanf("%d",&newNode->coef);
                printf("degree: ");
                scanf("%d",&newNode->deg);
        
            if(head==NULL)
            head=temp=newNode;
            
            else
            {
                temp->next=newNode;
                temp=newNode;
            }
        }
return head;
}

struct Node *add(struct Node *p1,struct Node *p2,struct Node *p3)
{
    struct Node *t1=p1,*t2=p2,*t3=p3;
    int i;

        while((t1!=NULL)&&(t2!=NULL))
        {
                newNode=(struct Node *)malloc(sizeof(struct Node));
                newNode->next=NULL;
            if(t1->deg==t2->deg)
            {
                newNode->deg=t1->deg;
                newNode->coef=t1->coef+t2->coef;
                t1=t1->next;
                t2=t2->next;
            }
        else 
        
            if(t1->deg>t2->deg)
            {
                newNode->deg=t1->deg;
                newNode->coef=t1->coef;
                t1=t1->next;
            }
            
            else
            {
                newNode->deg=t2->deg;
                newNode->coef=t2->coef;
                t2=t2->next;
            }
        
        if(p3==NULL)
            p3=t3=newNode;
        else
            {
                t3->next=newNode;
                t3=newNode;
            }
        
        }
        
        while(t1)
        {
            newNode=(struct Node *)malloc(sizeof(struct Node));
            newNode->next=NULL;
            newNode->deg=t1->deg;
            newNode->coef=t1->coef;
            t3->next=newNode;
            t3=newNode;
            t1=t1->next;
        }

        while(t2)
        {
            newNode=(struct Node *)malloc(sizeof(struct Node));
            newNode->next=NULL;
            newNode->deg=t2->deg;
            newNode->coef=t2->coef;
            t3->next=newNode;
            t3=newNode;
            t2=t2->next;
        }
    
    return p3;
}

void display_add(struct Node *head)
{
    struct Node *t=head;
        while(t)
        {
            printf("(%dx^%d)+",t->coef,t->deg);
            t=t->next;
        }
}


int main()
{
    int ch;
    int x,i;
    struct Node *p1=NULL,*p2=NULL,*p3=NULL;
    int n;
    char c;
    
    printf("1. Evaluate:\n2. Add Polynomial:\n");
    scanf("%d",&ch);
    
    
    switch (ch){
        case 1:
                printf("Enter number of elements: ");
	            scanf("%d",&x);
            	for (i=0;i<x; i++){
            		create();
            	}
            	display();
            	
            	evaluate();
            	break;
        
        case 2:
            	
                p1=create_add(p1);
                display_add(p1);
                p2=create_add(p2);
                display_add(p2);
                p3=add(p1,p2,p3);
                printf("\nthe addition is:");
                display_add(p3);
                break;
                
        default: printf("Wrong choice");

        }
    return 0;
}


/*

1. Evaluate:
2. Add Polynomial:
2

Enter no. of terms: 4

Enter the terms in descending order of degree
coefficient: 3
degree: 5
coefficient: 7
degree: 4
coefficient: 2
degree: 3
coefficient: 3
degree: 1
(3x^5)+(7x^4)+(2x^3)+(3x^1)+
Enter no. of terms: 3

Enter the terms in descending order of degree
coefficient: 2
degree: 5
coefficient: 3
degree: 3
coefficient: 7
degree: 1
(2x^5)+(3x^3)+(7x^1)+
the addition is:(5x^5)+(7x^4)+(5x^3)+(10x^1)+
*/

/*
1. Evaluate:
2. Add Polynomial:
1
Enter number of elements: 3
Enter degree: 3
Enter coefficient: 2
Enter degree: 2
Enter coefficient: 13
Enter degree: 0
Enter coefficient: -25
2x^3 + 13x^2 + -25x^0 + 
Enter value of variable x: -6

Evaluation of polynomial = 11
*/





