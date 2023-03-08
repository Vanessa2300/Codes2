#include<stdio.h>
#include<conio.h>

int main(){

//int arr[3][3]={{0,10,0},{20,0,0},{0,0,30}};
int arr1[50][50];
int arr2[50][50];
int arr3[50][50];
int i,j, count=0,x=1,y,z, row,col;
int sparse1[50][3];
int sparse2[50][3];
int sparse3[50][3];
//int transpose[50][50];

    printf("Enter number of rows: ");
    scanf("%d",&row);

    printf("Enter number of columns: ");
    scanf("%d",&col);

    printf("\nEnter elements for Matrix 1:\n");
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                printf("Enter element for [%d][%d]:",i,j);
                scanf("%d",&arr1[i][j]);
            }
        }

    printf("\nEnter elements for Matrix 2:\n");
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                printf("Enter element for [%d][%d]:",i,j);
                scanf("%d",&arr2[i][j]);
            }
        }


    printf("\nMatrix 1:\n");
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                printf(" %d ",arr1[i][j]);
            }
            printf("\n");
        }

    printf("\nMatrix 2:\n");
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                printf(" %d ",arr2[i][j]);
            }
            printf("\n");
        }


    //ADDITION OF MATRICES
    for(i=0;i<row;i++){
        for (j=0;j<col;j++){
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("\nMatrix 3:\n");
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                printf(" %d ",arr3[i][j]);
            }
            printf("\n");
        }


    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
           if(arr1[i][j]!=0){
                sparse1[x][0]=arr1[i][j];
                sparse1[x][1]=i;
                sparse1[x][2]=j;
                x++;
            }
        }
     }

    printf("\nSparse Matrix 1:\n");
       for(y=1;y<x;y++){
            for(z=0; z<3; z++){
                printf(" %d ",sparse1[y][z]);
            }
            printf("\n");
        }


     x=1;
     for(i=0;i<row;i++){
        for(j=0;j<col;j++){
           if(arr2[i][j]!=0){
                sparse2[x][0]=arr2[i][j];
                sparse2[x][1]=i;
                sparse2[x][2]=j;
                x++;
            }
        }
     }

    printf("\nSparse Matrix 2:\n");
        for(y=1;y<x;y++){
            for(z=0; z<3; z++){
                printf(" %d ",sparse2[y][z]);
            }
            printf("\n");
        }


    x=1;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
           if(arr3[i][j]!=0){
                sparse3[x][0]=arr3[i][j];
                sparse3[x][1]=i;
                sparse3[x][2]=j;
                x++;
            }
        }
    }

    printf("\nAddition of Sparse Matrix :\n");
       for(y=1;y<x;y++){
            for(z=0; z<3; z++){
                printf(" %d ",sparse3[y][z]);
            }
            printf("\n");
        }

getch();
return 0;
}

/*Enter number of rows: 2
Enter number of columns: 3

Enter elements for Matrix 1:
Enter element for [0][0]:1
Enter element for [0][1]:2
Enter element for [0][2]:3
Enter element for [1][0]:0
Enter element for [1][1]:0
Enter element for [1][2]:0

Enter elements for Matrix 2:
Enter element for [0][0]:1
Enter element for [0][1]:2
Enter element for [0][2]:7
Enter element for [1][0]:7
Enter element for [1][1]:0
Enter element for [1][2]:0

Matrix 1:
 1  2  3
 0  0  0

Matrix 2:
 1  2  7
 7  0  0

Matrix 3:
 2  4  10
 7  0  0

Sparse Matrix 1:
 1  0  0
 2  0  1
 3  0  2

Sparse Matrix 2:
 1  0  0
 2  0  1
 7  0  2
 7  1  0

Addition of Sparse Matrix :
 2  0  0
 4  0  1
 10  0  2
 7  1  0*/
