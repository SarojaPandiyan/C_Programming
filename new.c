//program to generate even sub matrix
#include<stdio.h>
int main()
{
    int i,j,n,c=1,s;
    printf("enter the no.of rows/cols:");
    scanf("%d",&n);
    int arr[n][n],temp[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            arr[i][j]=c;
            c++;
        }}
    if(n%2!=0)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
             temp[i][j]=arr[i][j];   
            }
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i%2!=0)
                {
                    temp[i][j]=arr[i][n-j-1];
                }
                else
                {
                    temp[i][j]=arr[i][j];
                }
            }
        }

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",temp[i][j]);
        }printf("\n");
    }
}