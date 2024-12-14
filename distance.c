#include<stdio.h>
#include<math.h>
struct points
{
    int x;
    
    int y;
}pt[2];
int main()
{
    for(int i=0;i<2;i++)
    {
        printf("\nEnter x and y coordinates:");
        scanf("%d %d",&pt[i].x,&pt[i].y);
    }
    float xdif=pow(pt[1].x-pt[0].x,2);
    float ydif=pow(pt[1].y-pt[0].y,2);
    float dist=sqrt(xdif+ydif);
    printf("\nthe distance is %f",dist);
}