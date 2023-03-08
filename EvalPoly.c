#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node
{ int deg,coef;
 struct Node *next;

}*head=NULL, *end;

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

int main(){
	int x,i,c;
	char con;
	//clrscr();
	printf("Enter number of elements: ");
	scanf("%d",&x);

	for (i=0;i<x; i++){
		create();
	}
	display();
	
	evaluate();

	
	//getch();
	return 0;

}


/*
Enter number of elements: 2
Enter degree: 2
Enter coefficient: 3
Enter degree: 3
Enter coefficient: 4
3x^2 + 4x^3 + 
Enter value of variable x: 2

Evaluation of polynomial = 44
*/
