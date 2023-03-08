#include<stdio.h>
int main()
{
  int array[100],n,c,d,swap;
  printf("***Program for Bubble Sort***\n");
  printf("enter number of elements \n");
  scanf("%d",&n);
  printf("enter elements \n",n);
  for(c=0;c<n;c++)
    scanf("%d",&array[c]);

  for(c=0;c<n-1;c++)
  {
    for(d=0;d<n-c-1;d++)
    {
      if(array[d]>array[d+1])
      {
        swap=array[d];
        array[d]=array[d+1];
        array[d+1]=swap;

      }
    }

}
printf("sorted list in ascending order:\n");
for(c=0;c<n;c++)

  printf("%d ",array[c]);


return 0;
}

/*
***Program for Bubble Sort***
enter number of elements
8
enter elements
56 24 33 87 65 31 73 11
sorted list in ascending order:
11 24 31 33 56 65 73 87
*/
