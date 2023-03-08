#include<stdio.h>
int n,f=-1,r=-1, tat[20],wt[20], k=0;
struct prs{
    int pid;
    int bt;
    int prt;
}queue[20];

void enqueue(struct prs a){
    if (r<n){
        queue[++r] = a;
    }
    else{
        printf("Queue full\n");
    }
}

void dequeue(){
    struct prs b = queue[++f];
    printf("P %d\t\t",b.pid);
    printf(" %d\t\t",b.bt);
    wt[k] = tat[k-1];
    printf(" %d\t\t",wt[k]);
    tat[k] = b.bt + wt[k];
    printf("%d\n",tat[k]);
    k++;
}

void schedule(struct prs p[]){
    int i;
    for ( i = 0; i < n; i++){   
        enqueue(p[i]);
    }
    for ( i = 0; i < n; i++){
        dequeue();
    }
}

int main(){
    int j, i;
    struct prs p[10];
    printf("Enter how many process u want \n");
    scanf("%d",&n);
    for ( i = 0; i < n; i++){
        printf("Enter process id\n");
        scanf("%d",&p[i].pid);
        printf("Enter process burst time\n");
        scanf("%d",&p[i].bt);
        printf("Enter process priority\n");
        scanf("%d",&p[i].prt);
    }
    for ( i = 0; i < n-1; i++){
        for ( j = i+1; j < n-i-1; j++){
            if (p[i].prt<p[j].prt){
                struct prs t = p[i];
                    p[i] = p[j];
                    p[j] = t;
            }
        }
    }
    for ( i = 0; i < n; i++){
        printf("process id: %d\n",p[i].pid);
        printf("process burst time : %d\n",p[i].bt);
        printf("Enter process priority : %d\n",p[i].prt);
    }
    printf("Pid\t BurstTime\t Waiting Time\t Turnnaround time\n");
    schedule(p);
    return 0;
}
