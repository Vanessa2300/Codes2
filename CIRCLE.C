#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node
{ int data;
 struct Node *next;

}*head=NULL, *end;

void create(){
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter Data: ");
	scanf("%d",&temp->data);

	if(head==NULL){
		head=temp;
		end=temp;
		end->next=head;
	}
	else{
		end->next=temp;
		end=temp;
		end->next = head;
	}
}

void insert_end(){
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter Data: ");
	scanf("%d",&temp->data);
		end->next=temp;
		end=temp;
		end->next=head;
}


void insert_start(){
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter Data: ");
	scanf("%d",&temp->data);
	temp->next = head;
	head =temp;
	end->next=head;
}

void insert_pos(){
      int pos,i;
      struct Node *t1, *t2, *temp;
      temp = (struct Node *)malloc(sizeof(struct Node));
      printf("Enter Data: ");
      scanf("%d",&temp->data);
      printf("Enter Position: ");
      scanf("%d",&pos);

      t2=head;
      for(i=0;i<pos-1;i++){
	t1=t2;
	t2=t1->next;
      }

      t1->next=temp;
      temp->next=t2;

}

void del_last(){
	struct Node *t1, *t2;
	t2=head;

	while(t2->next!=end){
		t1=t2;
		t2=t2->next;
	}

	t1->next = head;
	end=t1;
	free(t2);
}

void del_first(){
	struct Node *t1;
	t1=head;
	head = t1->next;
	end->next=head;
	free(t1);
}

void del_pos(){
	int i, pos;
	struct Node *t1, *t2;
	t2 =head;

	printf("Enter position: ");
	scanf("%d",&pos);

	for(i=0; i<pos-1;i++)
	{	t1=t2;
		t2 = t1->next;
	}

	t1->next=t2->next;
	free(t2);
}

void display(){
	struct Node *temp;
	temp=head;
	while (temp!=end){
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("%d->%d",end->data,head->data);
       //printf("NULL");

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
		case 1: insert_start();
			display();
			break;

		case 2: insert_end();
			display();
			break;

		case 3: insert_pos();
			display();
			break;

		case 4: del_first();
			display();
			break;

		case 5: del_last();
			display();
			break;

		case 6: del_pos();
			display();
			break;

        case 7: exit(0);
		default: printf("Wrong choice:");
	}

	printf("\nDo u want to continue? Y/n");
	scanf("%s", &con);
	}
	//getch();
	return 0;

}

/*
Enter number of elements: 4
Enter Data: 10
Enter Data: 20
Enter Data: 30' 
Enter Data: 40
10->20->30->40->10
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
Enter Data: 5
5->10->20->30->40->5
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
Enter Data: 50
5->10->20->30->40->50->5
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
Enter Data: 15
Enter Position: 3
5->10->15->20->30->40->50->5
Do u want to continue? Y/ny

Make a choice
1. Insert at first position
2. Insert at last position
3. Insert at ur choice position
4. Delete element at first position
5. Delete element at last position
6. Delete element at ur choice position
7. Exit
4
10->15->20->30->40->50->10
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
10->15->20->30->10
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
Enter position: 2
10->20->30->10
Do u want to continue? Y/nn
*/

