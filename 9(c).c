#include<stdio.h>
void ascending(int*,int);
void descending(int*,int);
void main()
{
    int arr[]={3,0,4,1,5},size=sizeof(arr)/sizeof(int);
    ascending(arr,size);
    descending(arr,size);
}
void ascending(int* a,int size)
{
    int t,i,j;
    for(i=0;i<size/2;i++)
    {
        for(j=0;j<size/2;j++)
        {
            if(a[i]<a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    printf("\nThe array arranged in ascending order is: ");
    for(i=0;i<size/2;i++)
    {
        printf("\n%d",*(a+i));
    }
    return;
}
void descending(int* a,int size)
{
    int t,i,j;
    for(i=size/2;i<size;i++)
    {
        for(j=size/2;j<size;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    printf("\nThe array arranged in descending order is: ");
    for(i=size/2;i<size;i++)
    {
        printf("\n%d",*(a+i));
    }
    return;
}