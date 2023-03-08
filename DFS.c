#include<stdio.h>
int n,Adj[20][20],visited[10],stack[10];
char vertices[10];
int top=-1;
void push(int v)
{
	if(top==9)
		printf("\nStack is full");
	else
		stack[++top]=v;
}

void pop()
{
	if(top==-1)
		printf("\nStack is empty");
	else
		//printf("%d\t",stack[top--]);
		top--;
}

void DFS(int V)
{
	int vertex = V,f;
	if(visited[vertex]!=1)
	{
		visited[vertex]=1;
		push(vertex);
		printf("%c\t",vertices[vertex]);
		f=0;
		for(int i=0;i<n;i++)
		{
			if(Adj[vertex][i]==1)
			{
				DFS(i);
				f=1;
			}
		}
		if(f==0)
			pop();

	}
}


void print_Adj()
{
	int i,j;
		printf("\n.........ADJACENCY MATRIX.........\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",Adj[i][j]);
		printf("\n");
	}
}


void main()
{
	printf("\nEnter number of vertices:");
	scanf("%d",&n);
	printf("\nEnter the vertices in ascending order: ");
	for(int i=0;i<n;i++)
	{
		scanf("%s",&vertices[i]);
	}
	printf("\nEnter the adjacency matrix:");
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
		stack[i]=0;
		for(int j=0;j<n;j++)
			scanf("%d",&Adj[i][j]);
	}

	print_Adj();

	printf("\nDFS:\n");
	DFS(0);
}
/*

Enter number of vertices:5

Enter the vertices in ascending order: A B C D E

Enter the adjacency matrix:
0 1 1 1 0
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1

.........ADJACENCY MATRIX.........
0       1       1       1       0
1       0       0       0       1
1       0       0       0       1
1       0       0       0       1
1       0       0       0       1

DFS:
A       B       E       C       D
*/
