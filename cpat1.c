#include<stdio.h>
#include <math.h>
int factorial(int num)
{
    if(num==0||num==1)
    {
        return 1;
    }
    else{
        num=num*factorial(num-1);
        return num;
    }
}
int combination(int row,int col)
{
    return factorial(row)/(factorial(col)*factorial(row-col));
}
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
            printf("%3d",combination(i,j));
        }
        printf("\n");
        }
}