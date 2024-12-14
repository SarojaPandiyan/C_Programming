#include<stdio.h>
int main() 
{
    char filename[10],line[300];
    FILE *fp;
    printf("Enter the file name: ");
    scanf("%s",filename);
    fp=fopen(filename,"r+");
    if(fp==NULL)
    {
        printf("Can't open file");
        return 1;
    }
    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        printf("%s",line);
    }
    fclose(fp);
    return 0;
}