#include<stdio.h>
#include<conio.h>
int n,Adj[20][20],visited[10],queue[10];
char vertices[10];
int front=0,rear=-1;
int vc =0;
void enqueue(int v)
{
	if (rear==9)
	{
		printf("\nQueue is full");
	}


	else
	{
		queue[++rear]=v;
		vc++;
	}

}

int dequeue()
{
	/*if(front==rear)
	{
		return -1;
	}

	else   */
	{
		vc--;
		return(queue[front++]);

	}
}

void BFS(int V)
{
	int vertex = V,f=0,i;

		enqueue(vertex);
		printf("%c\t",vertices[vertex]);
		visited[vertex] =1;
		while(vc!=0)
		{
			int tempvertex = dequeue();
			if(visited[tempvertex]==1)
			{
				for( i=0;i<n;i++)
				{
					if(Adj[tempvertex][i]==1)
					{
						if(!visited[i])
						{
							visited[i]=1;
							printf("%c\t",vertices[i]);
							enqueue(i);
						}
					}
				}
			}
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

int main()
{
	int i,j;
	//clrscr();
	printf("\nEnter number of vertices:");
	scanf("%d",&n);
	printf("\nEnter the vertices in ascending order: ");
	for( i=0;i<n;i++)
	{
		scanf("%s",&vertices[i]);
	}
	printf("\nEnter the adjacency matrix:");
	for( i=0;i<n;i++)
	{
		visited[i]=0;
		queue[i]=0;
		for( j=0;j<n;j++)
			scanf("%d",&Adj[i][j]);
	}

	print_Adj();


	printf("\nBFS:\n");

		BFS(0);
		getch();
		return 0;
}
/*
Enter number of vertices:5

Enter the vertices in ascending order: A B C D E

Enter the adjacency matrix:0 1 1 1 0
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

BFS:
A       B       C       D       E
*/
