#include<stdio.h>
#include<conio.h>

int main(){

//int arr[3][3]={{0,10,0},{20,0,0},{0,0,30}};
int arr[50][50];
int i,j, count=0,x=1,y,z, row,col;
int sparse[50][3];
int transpose[50][3];

    printf("Enter number of rows: ");
    scanf("%d",&row);

    printf("Enter number of columns: ");
    scanf("%d",&col);

    printf("Enter matrix elements:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("Enter element for [%d][%d]:",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\nOrignal Matrix\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf(" %d ",arr[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
           if(arr[i][j]!=0){
                sparse[x][0]=arr[i][j];
                sparse[x][1]=i;
                sparse[x][2]=j;
                x++;
                //count++;
            }
        }
        //sparse[0][2] = x-1;
    }


    printf("\nSparse Matrix:\n");

    for(y=1;y<x;y++){
        for(z=0; z<3; z++){
            printf(" %d ",sparse[y][z]);
        }
        printf("\n");
    }

   printf("\nTranspose of Sparse Matrix:\n");
     for (y=0; y<x; y++){
        for(z=0; z<3; z++){
            transpose[y][0]=sparse[y][0];
            transpose[y][1]=sparse[y][2];
            transpose[y][2]=sparse[y][1];
        }
    }


    for (y=1; y<x; y++){
        for(z=0; z<3; z++){
            printf(" %d ",transpose[y][z]);
        }
        printf("\n");
    }

getch();
return 0;
}
