#include<stdio.h>
#include<string.h>
void main()
{
    FILE *fp;
    int count=0;
    char line[200];
    fp=fopen("files.txt","r+");
    if(fp==NULL)
    {
        printf("\ncan't open");
    }
    while(fscanf(fp,"%s",line)!=EOF)
    {
        if(strcmp(line,"a")==0||strcmp(line,"an")==0||strcmp(line,"the")==0||strcmp(line,"A")==0||strcmp(line,"An")==0||strcmp(line,"The")==0)
        {
            count++;
        }
    }
    fclose(fp);
    printf("\nThe article's count is: %d",count);
}