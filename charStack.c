#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node {
    char data;
    struct Node *next;
}*top = NULL;

void push(char value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
            if (top == NULL) {
            newNode->next = NULL;
            } else {
            newNode->next = top;
            }
    top = newNode;
    printf("Node is Inserted\n\n");
}

char pop() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        struct Node *temp = top;
        char temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

void display() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        printf("The stack is \n");
        struct Node *temp = top;
        while (temp->next != NULL) {
            printf("%c\n||\n\\/\n", temp->data);
            temp = temp->next;
        }
        printf("%c\n||\n\\/\nNULL", temp->data);
    }
}
int main() {
    int choice;
    char value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1) {
            printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
            printf("\nEnter your choice : ");
            scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%c", &value);
                push(value);
                break;
            case 2:
                printf("Popped element is :%c\n", pop());
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nWrong Choice\n");
        }
    }
    return 0;
}
