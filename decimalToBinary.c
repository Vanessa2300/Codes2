#include<stdio.h>
#include<conio.h>

int stack[100];
int top = -1;

void push(int x){
    stack[++top]=x;
}

void pop(){
    top--;
}

void dec2bin(int num){
    if(num==0){
        printf("0");
        return;
    }

    while(num>0){
        push(num%2);
        num = num/2;
    }

    while(top!=-1){
        printf("%d",stack[top]);
        pop();
    }

}

int main(){

int n;
printf("Enter any Decimal Number: ");
scanf("%d",&n);

printf("\nBinary Equivalent: ");
dec2bin(n);
return 0;
}
