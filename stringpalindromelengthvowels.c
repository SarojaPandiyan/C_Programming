#include<stdio.h>
#include<string.h>
int palindrome(char*string)
{   int i;
    int length=strlen(string);
    char str[length];
    strcpy(str,string);
    for(i=0;i<length;i++)
    {
        if(str[i]!=string[length-i-1])
            return 0;
    }return 1;
}
int main()
{
char ch,str1[20],str2[20],temp[20];
int i,c,len,vow=0;
printf("Enter p for checking palindrome,l for length,v for no. of vowels:");
scanf("%c",&ch);
printf("enter a string : ");
scanf("%s",str1);
switch(ch)
{
case 'p':
{
    c=palindrome(str1);
    printf("%d",c);
    if(c==0)
    {
        printf("not palindrome");
        break;}
    else
       {printf(" palindrome");
        break;}

}
case 'l':
    {len=strlen(str1);
    printf("the length of the given string is %d",len);
    break;}
case 'v':
    {for(i=0;i<20;i++)
    {
    if(str1[i]=='a'|| str1[i]=='e'|| str1[i]=='i'|| str1[i]=='o'||str1[i]=='u')
    {
        vow++;
        if(vow>1)
        {printf("the given string contains more than one vowel");break;}}
}}}}