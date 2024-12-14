#include<stdio.h>
#include<string.h>
struct employee
{
    int empid;
    char empname[30];
    int salary;
}e[5];
void  display()
{
    for(int i=0;i<5;i++)
    {
        printf("\n Enter id,name,salary:");
        scanf("%d %s %d",&e[i].empid,e[i].empname,&e[i].salary);
    }
    for(int i=0;i<5;i++)
    {
    
        printf("\n%d %s %d",e[i].empid,e[i].empname,e[i].salary);
    }
    

}
void idsearch()
{
    printf("\nEnter id:");
    int idd;
    scanf("%d",&idd);
    for(int i=0;i<5;i++)
    {
        if(idd==e[i].empid)
        {
            printf("yes");
            break;
        }
    }
}
void salnam()
{
    for(int i=0;i<5;i++)
    {
        if(e[i].salary>10000)
        {
            printf("\n%s has salary higher than 10000",e[i].empname);
        }
    }
}

int main()
{
    display();
    idsearch();
    salnam();
}