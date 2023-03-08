#include<stdio.h>
int main()
{
    int cost[10][10],visited[10]={0},i,j,n,no_e=1,min,a,b,min_cost=0;
    printf("\n\tImplementation of Prim's Algorithm\n");
    printf("Enter number of nodes ");
    scanf("%d",&n);
    printf("Enter cost in form of adjacency matrix\n");
    //input graph
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            // cost is 0 then initialize it by maximum value
            if(cost[i][j]==0)
              cost[i][j]=1000;
        }
    }

    // logic for finding minimum cost spanning tree
    visited[1]=1; // visited first node
    while(no_e<n)
    {
        min=1000;
        // in each cycle find minimum cost
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        //if node is not visited
        if(visited[b]==0)
        {
            printf("\n%d to %d  cost=%d",a,b,min);
            min_cost=min_cost+min;
            no_e++;
        }
        visited[b]=1;
        // initialize with maximum value you can also use any other value
        cost[a][b]=cost[b][a]=1000;
    }
    printf("\nminimum weight is %d",min_cost);
    return 0;
}

/*
        Implementation of Prim's Algorithm
Enter number of nodes 5
Enter cost in form of adjacency matrix

0 10 3 20 0
0 0 0 5 0
0 2 0 0 15
0 0 0 0 11
0 0 0 0 0

1 to 3  cost=3
3 to 2  cost=2
2 to 4  cost=5
4 to 5  cost=11
minimum weight is 21
*/
