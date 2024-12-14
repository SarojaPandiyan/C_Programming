#include<stdio.h>
#include<string.h>
#include<ctype.h>
void doEncoding(FILE* input,FILE* output)
{
    char ch;
    int num;
    char lowest;
    while((ch=fgetc(input))!=EOF)
    {
        if(isalpha(ch) && islower(ch))
        {
            lowest='a';
        }
        else if(isalpha(ch) && isupper(ch))
        {
            lowest='A';
        }
        ch = ch-lowest+3;
        fputc(ch,output);
    }
}
void main()
{
    FILE *fp1,*fp2;
    fp1=fopen("inputfile.txt","r");
    fp2=fopen("outputfile.txt","w");
    doEncoding(fp1,fp2);
    fclose(fp1);
    fclose(fp2);
}