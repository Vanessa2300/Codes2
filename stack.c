#include <stdio.h>
#include<conio.h>

int stack[100], n=100, top=-1;
void push(int val) {
   if(top>=n-1)
   printf("Stack Overflow");
   else {
      top++;
      stack[top]=val;
   }
}
void pop() {
   if(top<=-1)
   printf("Stack Underflow");
   else {
       printf("The popped element is %d\n",stack[top]);
      top--;
   }
}
void display() {
   if(top>=0) {
      for(int i=top; i>=0; i--){
      printf("%d\n||\n\\/\n",stack[i]);
      }
      printf("NULL");
   } else
   printf("Stack is empty");
}
void main() {
   int ch, val;
   
   do {
    printf("\n1) Push in stack\n");
    printf("2) Pop from stack\n");
    printf("3) Display stack\n");
    printf("4) Exit\n");
      printf("\nEnter choice: ");
      scanf("%d",&ch);
      switch(ch) {
         case 1: {
           printf("\nEnter value to be pushed:");
            scanf("%d",&val);
            push(val);
            break;
         }
         case 2: {
            pop();
            display();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            printf("\nExit");
            break;
         }
         default: {
            printf("Invalid Choice");
         }
      }
   }while(ch!=4);
   getch();
}
