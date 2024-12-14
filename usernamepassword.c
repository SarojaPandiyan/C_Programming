#include<stdio.h>
#include<string.h>
int main()
{
    char name[10],password[10];
    int i,l,k,c=0;
    char UN[5][15]={"ABI","ANU","RAM","JOHN","MANI"};
    char PW[5][15]={"abi","anu","ram","john","mani"};
    char CM[5][15]={"hi","hello","welcome","very good","bye"};
    printf("enter the username:");
    scanf("%s",name);
    printf("enter the password:");
    scanf("%s",password);
    for(i=0;i<5;i++)
    {
        l=strcmp(name,UN[i]);
        k=strcmp(password,PW[i]);
        if(l==0&k==0){
            printf("%s",CM[i]);
            c=1;
            break;}
        
    }if(c==0)
        printf("wrong password");
    }
    
