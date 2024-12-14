#include<stdio.h>
#include<ctype.h>
#include<string.h>
void main()
{
    FILE *fp;
    char ch,line[100];
    int vowel=0,cons=0,upper=0,lower=0,special=0,digits=0,word=0,lines=0;
    fp=fopen("output.txt","r+");
    while((ch=getc(fp))!=EOF)
    {
        if(isalpha(ch))
        {
            if(isupper(ch))
                ++upper;
            else    
                ++lower;
            ch=tolower(ch);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            {
                ++vowel;
            }
            else
            {
                ++cons;
            }
        }
        else if(isdigit(ch))
            digits++;
        else if(ch==' ')
        {
            special++;
        }
        else
        {
            special++;
        }

    }
    int count =ftell(fp);
    rewind(fp);
    while(fscanf(fp,"%s",line)!=EOF)
    {
        word++;
    }
    rewind(fp);
    while(fgets(line,sizeof(line),fp))
    {
        lines++;
    }
    fclose(fp);
    printf("%d",count);
    printf("%d,%d,%d,%d,%d,%d,%d,%d",vowel,cons,upper,lower,special,digits,word,lines);
}