#include<stdio.h>
#include<stdlib.h>
#define min(a,b) a<b?a:b;

void main()
{
    int n,ar[10],x,i,a,b,c,offset;
    printf("***Program for Fibonacci Search***\n");
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("\nEnter elements of array(in sorted order): ");
    for(i=0;i<n;i++)
	{
        scanf("%d",&ar[i]);
    }
    printf("\nEnter the element to be searched:");
    scanf("%d",&x);
    a=0;
    b=1;
    c=a+b;
    while(c<n)
	{
        a=b;
        b=c;
        c=a+b;
    }
    offset=-1;
    while(c>1)
	{
		i=min(offset+a,n-1);
        if(ar[i]<x)
		{
            c=b;
            b=a;
            a=c-b;
            offset=i;
        }
		else if(ar[i]>x)
		{
            c=a;
            b=b-a;
            a=c-b;
        }
        else
		{
            printf("Element %d is found at position %d",x,i+1);
            return;
        }
    }
    if(b && ar[offset+1]==x)
	{
        printf("Element %d is found at index %d",x,offset);
        return;
    }
    printf("\nElement not found.");


}

/*
***Program for Fibonacci Search***
Enter number of elements:8

Enter elements of array(in sorted order):
11 24 31 33 56 65 73 87

Enter the element to be searched:24
Element 24 is found at position 2
*/
