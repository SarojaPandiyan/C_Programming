#include<stdio.h>
#include<string.h>
struct emp{
    char name[20];int id, bp,da;int hra;int gsal;int nsal;int it;
}e[3],e1;
void getele()
{int i,j,temp;
    for(i=0;i<3;i++)
    {
        printf("\nenter name id bp da hra:");
        scanf("%s %d %d %d %d",e[i].name,&e[i].id,&e[i].bp,&e[i].da,&e[i].hra);
        e[i].gsal=e[i].bp+e[i].da+e[i].hra;
        printf("enter income tax value:");
        scanf("%d",&e[i].it);
        printf("name is %s id is %d gross salary is %d",e[i].name,e[i].id,e[i].gsal);
}}
void netsal()
{  int i;
 for(i=0;i<3;i++)
     {e[i].nsal=(e[i].gsal-e[i].it);
        printf("\nthe net salary of %s is %d",e[i].name,e[i].nsal);
}}
void sort()
{int i,j;
     for(i=0;i<3;i++)
    {
        for(j=i+1;j<3;j++)
        {if(strcmp(e[i].name,e[j].name)>0){
            e1=e[i];
            e[i]=e[j];
            e[j]=e1;
        }}
        }

    }



int main()
{   int i; 
   getele();
   netsal();
   sort();
   for(i=0;i<3;i++)
   {
        
        printf("\nname is %s id is %d gross salary is %d the net salary is %d",e[i].name,e[i].id,e[i].gsal,e[i].nsal); 
   }
    }

