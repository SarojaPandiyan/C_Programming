#include<stdio.h>
#include<string.h>
struct date
{
    int day;
    int mon;
    int yr;
};
struct book
{
    int bid;
    char bname[20],aname[20],pname[20];
    int cost,qnt;
    struct date d; 
}b[10];
void det()
{
    int i;
    for(i=0;i<3;i++)
    {
        printf("\nEnter the bid,bname,aname,pname,cost,qnt,day,mon,yr:");
        scanf("%d %s %s %s %d %d %d %d %d",&b[i].bid,b[i].bname,b[i].aname,b[i].pname,&b[i].cost,&b[i].qnt,&b[i].d.day,&b[i].d.mon,&b[i].d.yr);
        printf("%d %s %s %s %d %d %d %d %d",b[i].bid,b[i].bname,b[i].aname,b[i].pname,b[i].cost,b[i].qnt,b[i].d.day,b[i].d.mon,b[i].d.yr);
    }}
    void costlier()
    {   int i;
        int max=b[0].cost,index;
        for(i=0;i<3;i++)
        {
            if(max<b[i].cost)
            {
                max=b[i].cost;
                index=i;
            }
        }
        printf("\n%d %s %s %s %d %d %d %d %d",b[index].bid,b[index].bname,b[index].aname,b[index].pname,b[index].cost,b[index].qnt,b[index].d.day,b[index].d.mon,b[index].d.yr);
    }
    void titlesearch()
    {
        char bookn[20];
        int i;
        printf("\nenter the book name:");
        scanf("%s",bookn);
        for(i=0;i<3;i++)
        {
            if((strcmp(bookn,b[i].bname))==0)
            printf("\n%d %s %s %s %d %d %d %d %d",b[i].bid,b[i].bname,b[i].aname,b[i].pname,b[i].cost,b[i].qnt,b[i].d.day,b[i].d.mon,b[i].d.yr);
        }
    }
    void authorsearch()
    {
        char author[20];
        int i;
        printf("\nenter author name:");
        scanf("%s",author);
        for(i=0;i<3;i++)
        {
            if((strcmp(author,b[i].aname))==0)
            printf("\n%d %s %s %s %d %d %d %d %d",b[i].bid,b[i].bname,b[i].aname,b[i].pname,b[i].cost,b[i].qnt,b[i].d.day,b[i].d.mon,b[i].d.yr);

        }
    }
    void pubsearch()
    {   int i;
        char pub[20];
        printf("\nenter the publisher name:");
        scanf("%s",pub);
        for(i=0;i<3;i++)
        {
            if((strcmp(pub,b[i].pname))==0)
            printf("\n%d %s %s %s %d %d %d %d %d",b[i].bid,b[i].bname,b[i].aname,b[i].pname,b[i].cost,b[i].qnt,b[i].d.day,b[i].d.mon,b[i].d.yr);
        }

    }
    void yr()
    {
        int year;int i;
        printf("\nenter the year:");
        scanf("%d",&year);
        for(i=0;i<3;i++)
        {
            if((year==b[i].d.yr))
            printf("\n%d %s %s %s %d %d %d %d %d",b[i].bid,b[i].bname,b[i].aname,b[i].pname,b[i].cost,b[i].qnt,b[i].d.day,b[i].d.mon,b[i].d.yr);
        }
    }
    void main()
    {
        det();
        costlier();
        titlesearch();
        authorsearch();
        pubsearch();
        yr();
    }
    

        
    
