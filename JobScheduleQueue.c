#include<stdio.h>   
#include<stdlib.h>  
#define maxsize 10

int pqPriority[maxsize]; 
int pqAt[maxsize];
int pqBt[maxsize];
int pqPid[maxsize];
int pqWt[maxsize];
int pqSt[maxsize];
int pqTt[maxsize];
int front = -1, rear = -1;  

void enqueue()  
{  
    int pid;
    int bt;
    int priority;
    int at;
    
        printf("\nEnter pid: ");
        scanf("%d",&pid);
        
        printf("Enter Burst time: ");
        scanf("%d",&bt);
        
        printf("Enter arrival Time: ");
        scanf("%d",&at);
        
        printf("Enter priority: ");
        scanf("%d",&priority);
        
    
  
    if(rear == maxsize-1)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else   
    {  
        rear = rear+1;  
    }  
    pqPid[rear] = pid;  
    pqBt[rear]=bt;
    pqPriority[rear]=priority;
    pqAt[rear]=at;
    printf("\nValue inserted ");  
      
}  

void dequeue()  
{  
    int item;   
    if (front == -1 || front > rear)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
              
    }  
    else  
    {  
        item = pqPid[front];  
        if(front == rear)  
        {  
            front = -1;  
            rear = -1 ;  
        }  
        else   
        {  
            front = front + 1;  
        }  
        printf("\nProcess P%d has been dequed ",item);  
    }  
      
      
}  

void display()  
{  
    int i;  
    if(rear == -1)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n"); 
        
        printf("\nPID\tBurstTime\tArrivalTime\tPriority");
        for(i=front;i<=rear;i++)  
        {  
            printf("\nP%d\t\t%d\t\t%d\t\t%d\n",pqPid[i],pqBt[i],pqAt[i],pqPriority[i]);  
        }     
    }  
} 

void startTime(){
    int i=0;
    pqSt[0]=0;
    for(i=1;i<rear+1;i++){
            pqSt[i]=pqBt[i-1] + pqSt[i-1];
    }
    
    pqSt[i]=pqBt[i-1]+pqSt[i-1];
    
    //display start time
    /*for(i=0;i<rear+1;i++){
            printf("%d\t",pqSt[i]);
            
    }*/
    
}

void turnAroundTime(){
    int i=0;
    float avgtt,sum=0;
    pqTt[0]=pqBt[0];
    for(i=1;i<rear+1;i++){
            pqTt[i]=pqSt[i+1] - pqAt[i];
    }
    
    /*printf("\n");
    for(i=0;i<rear+1;i++){
            printf("%d\t",pqTt[i]);
    }*/
    
    for(i=0;i<rear+1;i++){
            sum = sum + pqTt[i];
    }
    
    avgtt = sum / i;
    
    printf("\nAverage turnAroundTime= %f",avgtt);
}


void waitingTime(){
    int i=0;
    float avgwt,sum=0;
    for(i=0;i<rear+1;i++){
            pqWt[i]=pqSt[i] - pqAt[i];
    }
    
    //display start time
    /*for(i=0;i<rear+1;i++){
            printf("%d\t",pqWt[i]);
            
    }*/
    
    for(i=0;i<rear+1;i++){
            sum = sum + pqWt[i];
    }
    
    avgwt = sum / i;
    
    printf("\nAverage waitingTime= %f",avgwt);
    
    
    
}


int main(){
    
    int n, i = 0;
    
    printf("Enter number of processes: ");
    scanf("%d",&n);
    
    for (i=0;i<n;i++){
        enqueue();
    }
    
   
    
    display();
    startTime();
    waitingTime();
    turnAroundTime();
    
    printf("\nDequeing Process.... ");
    dequeue();
    
    display();
    
    return 0;
}

/*
Enter number of processes: 4

Enter pid: 1
Enter Burst time: 6
Enter arrival Time: 0
Enter priority: 1

Value inserted 
Enter pid: 2
Enter Burst time: 8
Enter arrival Time: 1
Enter priority: 2

Value inserted 
Enter pid: 3
Enter Burst time: 3
Enter arrival Time: 2
Enter priority: 0

Value inserted 
Enter pid: 4
Enter Burst time: 4
Enter arrival Time: 3
Enter priority: 3

Value inserted 
printing values .....

PID     BurstTime       ArrivalTime     Priority
P1              6               0               1

P2              8               1               2

P3              3               2               0

P4              4               3               3

Average waitingTime= 7.750000
Average turnAroundTime= 13.000000
Dequeing Process.... 
Process P1 has been dequed 
printing values .....

PID     BurstTime       ArrivalTime     Priority
P2              8               1               2

P3              3               2               0

P4              4               3               3
*/