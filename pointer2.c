#include<stdio.h>
int main()
{
    int arr[]={10,15,25,35,72,56,42.7};
    int *p=arr;
    int num,c=0,i;
    printf("Enter a number:");
    scanf("%d",&num);
    for(i=0;i<8;i++)
    { if(num==*(p+i))
       { printf("the given number is present in the given array");
        c=1;
        break;}}
    if(c==0)
    printf("the given number is not present in the given array");

}
