//second largest number in the given array
#include<stdio.h>
int main()
{
    int i,n,m,sm,arr[20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sm=arr[0];
    m=arr[0];
    for(i=0;i<n;i++)
    {
    if(m<arr[i])
    {
        sm=m;
        m=arr[i];
    }

    else if(arr[i]>sm && arr[i]<m)
        sm=arr[i];



    }
    printf("%d",sm);

}