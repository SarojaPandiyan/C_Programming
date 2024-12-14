#include<stdio.h>
#include<string.h>
struct student{
    char name[20];
    int rno;
    float m1,m2,m3,m4,m5;
    float total;

}s;
int main()
{
int i,j;
struct student st[3];
float max;
char nam[20];
int avg;
for(i=0;i<3;i++)
{   st[i].total=0;
    printf("enter the name:");
    scanf("%s",st[i].name);
    printf("enter the roll no:");
    scanf("%d",&st[i].rno);
    printf("enter five sub marks:");
    scanf("%f %f %f %f %f",&st[i].m1,&st[i].m2,&st[i].m3,&st[i].m4,&st[i].m5);
    st[i].total+=st[i].m1+st[i].m2+st[i].m3+st[i].m4+st[i].m5;
}
max=st[0].total;
for(i=0;i<3;i++)
{
    if(max<st[i].total)
        max=st[i].total;
}
printf("the max score is %f",max);

for(i=0;i<3;i++)
{
    if(max==st[i].total)
        printf("\n%s got more score",st[i].name);
        break;}
avg=0;
for(i=0;i<3;i++){
    avg+=st[i].total;
}
printf("\nthe average of class is %f\n",avg/3);
printf("enter the name to compare;");
scanf("%s",nam);
for(i=0;i<3;i++)
{
if(strcmp(nam,st[i].name)==0){
    printf("%s\n %d\n %f\n",st[i].name,st[i].rno,st[i].total);
}
}
for(i=0;i<3;i++)
{
 for(j=i+1;j<3;j++)
 {
   if(strcmp(st[i].name,st[j].name)>0)
    {    s=st[i];
        st[i]=st[j];
            st[j]=s;
 }}
}
for(i=0;i<3;i++)
{
    printf("The name is %s and roll no is %d and total is %f",st[i].name,st[i].rno,st[i].total);
}
return 0;
}