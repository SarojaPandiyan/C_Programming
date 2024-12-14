//second largest negative number
#include<stdio.h>
int main()
{
    int i,n,arr[20],arr1[20],c=0,m,sm;
    printf("enter the no. of elements in the array:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            arr1[c]=arr[i];
            c++;
            printf("%d  ",arr1[c-1]);
        }
    }
    m=arr1[0];
    sm=arr1[1];
    for(i=0;i<c;i++)
    {
        if(arr1[i]>m)
       { sm=m;
        m=arr1[i];
        }
        else if(arr1[i]>sm && arr1[i]<m)
            sm=arr1[i];
        
    }
    printf("\n%d  ",sm);
    printf("%d",m);

}