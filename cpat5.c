#include<stdio.h>
void main()
{
    int row=5,i,j,counter=1;
    for(i=0;i<row;i++)
    {
        for(j=row-1;j>=i;j--)
        {
            printf(" ");
        }
        for(j=0;j<=i;j++)
        {
            printf("%3d",counter);
            counter++;
        }
        printf("\n");
    }}
