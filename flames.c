#include<stdio.h>
#include<string.h>
int main()
{
    char n1[30],n2[30],temp[20];
    int i,j,t1,t2,t;
    printf("Enter the first name:");
    scanf("%s",n1);
    printf("%d ",strlen(n1));
    printf("Enter the second name:");
    scanf("%d",n2);
    t1=(strlen(n1)+strlen(n2));
    printf("%d ",t1);
    for(i=0;i<strlen(n1);i++)
    {
        for(j=0;j<strlen(n2);j++)
    {
            if(n1[i]==n2[j])
            {
                temp[i]=n1[i];}
            
    }
    }
    t2=t1-(2*(strlen(temp)));
    t=t2%6;
    printf("%d ",t);
    switch(t)
    {
        case 5:
         {printf("friends");
         break;}
        case 0:
            {
            printf("love");
            break;}
        case 1:
            {printf("affection");
            break;}
        case 2:
            {printf("marriage");
            break;}
        case 3:
            {printf("Enemy");
            break;}
        case 4:
            {printf("siblings");
             break;}
    }


}