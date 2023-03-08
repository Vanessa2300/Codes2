#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
}*head=NULL, *end=NULL;

void create(){
	struct Node *temp;
	temp= (struct Node *)malloc(sizeof(struct Node));

	printf("Enter the data: ");
	scanf("%d",&temp->data);

	temp->next=NULL;
	temp->prev=NULL;

	if(head==NULL){
		head=temp;
		end=temp;
	}
	else{
		end->next=temp;
		end->prev=end;
		end=temp;
	}
}

void insert_first(){
	struct Node *temp;
	printf("Inserting element at 1st position:\n");

	temp=(struct Node *)malloc(sizeof(struct Node));

	printf("Enter data: ");
	scanf("%d",&temp->data);

	//temp=head;
       //	head->prev=temp;
	temp->next=head;
	temp->prev=NULL;
	head->prev=temp;
	head=temp;
}

void insert_end(){
	struct Node *temp;
	printf("Inserting element at end position:\n");

	temp=(struct Node *)malloc(sizeof(struct Node));

	printf("Enter data: ");
	scanf("%d",&temp->data);

	end->next=temp;
	temp->next=NULL;
	temp->prev=NULL;
	temp->prev=end;
	end=temp;
}

void insert_pos(){
	int pos,i;
	struct Node *t1, *t2, *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
	printf("Inserting element at choice position: \n");
	printf("Enter position: ");
	scanf("%d",&pos);
	printf("Enter data: ");
	scanf("%d",&temp->data);

	t2=head;
	for(i=0; i<pos-1; i++){
		t1=t2;
		t2=t2->next;
	}

    temp->next=t2;
	t1->next=temp;
	t2->prev=temp;
	temp->prev=t1;
}

void delete_end(){
	struct Node *temp, *t;
	/*temp = end;
	end = end->prev;
	end->next=NULL;
	end=NULL;
	free(temp);*/

	temp = head;

	while(temp->next!=NULL){
		t=temp;
		temp = temp->next;
	}

	t->next=NULL;
	free(temp);
	//t->prev->next = NULL;

}

void delete_start(){
	struct Node *temp;

	temp=head;
	head=head->next;
	free(temp);
}

void delete_pos(){
	int pos,i;
	struct Node *t1, *temp;

	printf("Enter position to delete:");
	scanf("%d",&pos);

	temp=head;
	for(i=0; i<pos-1; i++){
		t1=temp;
		temp=temp->next;
	}

	//temp=t1->next;
       //	t1->next =t2;
	t1->next=temp->next;
	t1->next->prev=t1;
	free(temp);
}

void display(){
	struct Node *t1, *t2, *temp;
	temp=head;
	//t2=end;
	printf("NULL->");
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->next;
	}

	printf("NULL\n");

       //	printf("NULL");
}

void main(){

	int x,i,c;
	char con;
	//clrscr();
	printf("Enter number of elements: ");
	scanf("%d",&x);

	for (i=0;i<x; i++){
		create();
	}
	display();

	printf("\nDo u want to continue? Y/n");
	scanf("%s", &con);
	
	while ( con =='y'|| con == 'Y'){
	printf("\nMake a choice\n");
	printf("1. Insert at first position\n");
	printf("2. Insert at last position\n");
	printf("3. Insert at ur choice position\n");
	printf("4. Delete element at first position\n");
	printf("5. Delete element at last position\n");
	printf("6. Delete element at ur choice position\n");
	printf("7. Exit\n");
	scanf("%d",&c);

	switch(c){
		case 1: insert_first();
			display();
			break;

		case 2: insert_end();
			display();
			break;

		case 3: insert_pos();
			display();
			break;

		case 4: delete_start();
			display();
			break;

		case 5: delete_end();
			display();
			break;

		case 6: delete_pos();
			display();
			break;

	    case 7: exit(0);
		default: printf("Wrong choice:");
	}

    printf("\nDo u want to continue? Y/n");
	scanf("%s", &con);
	}

getch();
}

/*
Enter number of elements: 4
Enter the data: 10
Enter the data: 20
Enter the data: 30
Enter the data: 40
NULL->10->20->30->40->NULL

Do u want to continue? Y/ny

Make a choice
1. Insert at first position
2. Insert at last position
3. Insert at ur choice position
4. Delete element at first position
5. Delete element at last position
6. Delete element at ur choice position
7. Exit
1
Inserting element at 1st position:
Enter data: 5
NULL->5->10->20->30->40->NULL

Do u want to continue? Y/ny

Make a choice
1. Insert at first position
2. Insert at last position
3. Insert at ur choice position
4. Delete element at first position
5. Delete element at last position
6. Delete element at ur choice position
7. Exit
2
Inserting element at end position:
Enter data: 50
NULL->5->10->20->30->40->50->NULL

Do u want to continue? Y/ny

Make a choice
1. Insert at first position
2. Insert at last position
3. Insert at ur choice position
4. Delete element at first position
5. Delete element at last position
6. Delete element at ur choice position
7. Exit
3
Inserting element at choice position: 
Enter position: 3
Enter data: 15
NULL->5->10->15->20->30->40->50->NULL

Do u want to continue? Y/ny

Make a choice
1. Insert at first position
2. Insert at last position
3. Insert at ur choice position
4. Delete element at first position
5. Delete element at last position
6. Delete element at ur choice position
7. Exit
y 4
NULL->10->15->20->30->40->50->NULL

Do u want to continue? Y/ny

Make a choice
1. Insert at first position
2. Insert at last position
3. Insert at ur choice position
4. Delete element at first position
5. Delete element at last position
6. Delete element at ur choice position
7. Exit
5
NULL->10->15->20->30->40->NULL

Do u want to continue? Y/ny

Make a choice
1. Insert at first position
2. Insert at last position
3. Insert at ur choice position
4. Delete element at first position
5. Delete element at last position
6. Delete element at ur choice position
7. Exit
6
Enter position to delete:3
NULL->10->15->30->40->NULL

Do u want to continue? Y/nn
*/