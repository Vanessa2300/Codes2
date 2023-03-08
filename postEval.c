#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>

#define max 10


int s[max];
int top =-1;

void push(int x){
    top ++;
    s[top]=x;
}

int pop(){
    int m;
    m=s[top];
    top--;
    return m;
}

void eval_postfix(char ch){
    
    int x,y,z;
    
    switch(ch){
        case '+':
            x = pop();
            y = pop();
            z = y + x;
            push(z);
            break;
            
        case '-':
            x = pop();
            y = pop();
            z = y - x;
            push(z);
            break;
            
        case '*':
            x = pop();
            y = pop();
            z = y * x;
            push(z);
            break;
            
        case '/':
            x = pop();
            y = pop();
            z = y / x;
            push(z);
            break;
            
        case '^':
            x = pop();
            y = pop();
            z = pow(y,x);
            push(z);
            break;
    }
    
}

void main(){
    
    char ch;
    int ans;
    printf("Enter postfix expression: ");
    while((ch=getchar())!='\n'){
        if(isdigit(ch)){
            push(ch-48);
        }else{
            eval_postfix(ch);
        }
    }
    
    ans = pop();
    printf("The answer is: %d",ans);
    getch();
    
}