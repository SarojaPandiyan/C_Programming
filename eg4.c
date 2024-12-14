#include<stdio.h>
int isprime(int num)
{
    int c=0,i;
    for(i=2;i<num;i++)
    {
        if(num%i==0)
        {
            c=1;
            break;
        }
    }
    if(c==0)
        return 1;
    else
        return 0;
}
int main()
{
    int a[20],i,j,n;
    int c=0,s=0;
    scanf("%d",&n);
    a[0]=1;
    
    for(i=0;i<=n;i++)
    {
         for(j=0;j<i;j++){

           if()
            {
                c=1;
                break;
            }
        }}
    
}
