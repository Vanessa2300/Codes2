#include<stdio.h>
#include<conio.h>

int main(){
    int poly1[50], poly2[50], polyadd[50];
    int coeffiecient, hdegree1, hdegree2, coef,deg;
    int i,j;


    //For  Polynomial 1
    printf("Enter Highest degree for polynomial 1: ");
    scanf("%d",&hdegree1);

    printf("Enter number of coefficients: ");
    scanf("%d",&coeffiecient);

    for (j=0;j<hdegree1+1;j++){
        poly1[j]=0;
    }

    for (i=0; i<coeffiecient; i++){
        printf("Enter coefficient: ");
        scanf("%d",&coef);
        printf("Enter degree: ");
        scanf("%d",&deg);

        poly1[deg]= coef;
    }

    for (i=hdegree1;i>=0;i--){
        if(poly1[i]!=0){
            printf("%dx^%d + ", poly1[i],i);
        /*if(poly1[i+1]!=0){
            printf("+ ");
        }*/
        }
        //printf("+");
    }

    //For  Polynomial 2
    printf("\nEnter Highest degree for polynomial 2: ");
    scanf("%d",&hdegree2);

    printf("Enter number of coefficients: ");
    scanf("%d",&coeffiecient);

    for (j=0;j<hdegree2+1;j++){
        poly2[j]=0;
    }

    for (i=0; i<coeffiecient; i++){
        printf("Enter coefficient: ");
        scanf("%d",&coef);
        printf("Enter degree: ");
        scanf("%d",&deg);

        poly2[deg]= coef;
    }

    for (i=hdegree2;i>=0;i--){
        if(poly2[i]!=0){
            printf("%dx^%d + ", poly2[i],i);
        /*if(poly2[i+1]!=0){
            printf("+ ");
        }*/
        }
        //printf("+");
    }


    if (hdegree1>hdegree2){
        deg = hdegree1;
    }else if(hdegree2>hdegree1){
        deg = hdegree2;
    }else{
        deg = hdegree1;
    }

    for (j=0;j<=deg;j++){
        polyadd[j]=0;
    }

    for (i=0; i<=deg; i++){
        polyadd[i] = poly1[i] + poly2[i];
    }


    printf("\nAddition of Polynomials: \n");

    for (i=deg+1; i>=0 ; i--){
        if(polyadd[i]!=0){
            printf("%dx^%d +", polyadd[i],i);
        /*if(polyadd[i+1]!=0){
            printf("+ ");
        }*/
        }
        //printf("+");
    }




getch();
return 0;
}

/*Enter Highest degree for polynomial 1: 3
Enter number of coefficients: 2
Enter coefficient: 3
Enter degree: 3
Enter coefficient: 4
Enter degree: 2
3x^3 + 4x^2 +
Enter Highest degree for polynomial 2: 5
Enter number of coefficients: 3
Enter coefficient: 2
Enter degree: 3
Enter coefficient: 4
Enter degree: 5
Enter coefficient: 3
Enter degree: 1
4x^5 + 2x^3 + 3x^1 +
Addition of Polynomials:
4x^5 + 5x^3 + 4x^2 + 3x^1 +
*/
