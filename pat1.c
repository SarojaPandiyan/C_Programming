#include<stdio.h>
int main()
{
    int i,j,r;
    printf("enter the radius:");
    scanf("%d",&r);
    for(i=-r;i<r;i++)
    {
        for(j=-r;j<r;j++)
        {
            if((i*i)+(j*j)<(r*r))
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}