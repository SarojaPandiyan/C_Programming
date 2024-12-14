#include<stdio.h>
int main()
{
    int i,j,n,arr[20],flag=0,c=1;
    printf("Enter the number:");
    scanf("%d",&n);
    arr[0]=1;
    arr[1]=2;
    for(i=3;i<=n;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0)
                {flag=1;
                break;}
        }
        if(flag==0)
        {    c++;
            arr[c]=i;
            printf("%d",arr[c]);
        }

    }
    for(i=0;i<c;i++)
    {
        for(j=0;j<i;j++)
        {
            printf("%d ",arr[j]);
        }
        printf("\n");
    }
}