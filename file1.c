#include<stdio.h>
void main()
{
FILE *pt;
char c[100];
pt=fopen("sample.txt","r");
if(pt==NULL)
printf("Error");
else
fgets(c,100,pt);
printf("%s",c);
fclose(pt);
}