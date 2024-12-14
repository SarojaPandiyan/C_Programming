#include<stdio.h>
void main()
{
    int row=5,i,j;
    for(i=0;i<row;i++)
    {
        for(j=row-1;j>=i;j--)
        {
            printf(" ");
        }
        for(j=0;j<=i;j++)
        {
            printf("%3d",i+1);
        }
        printf("\n");
    }
}
