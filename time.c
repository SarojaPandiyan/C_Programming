#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void display(char str[100])
{
   char* h=strtok(str,":");
   if(h==12 && str[8:]=="AM")
        printf("%s:%s","00",str[3:8]);
    else if(str[8:]=="AM")
        printf("%s",str[0:8]);
    else if(h==12 && str[8:]=="PM")
        printf("%s",str[0:8]);
    else
        printf("%d:%s",12+h,str[3:8]);
}
int main()
{
    char string[100];
    printf("enter the time;");
    scanf("%s",string);
    display(string);
}