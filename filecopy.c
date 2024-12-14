#include<stdio.h>
#include<stdlib.h>
int main()
{
    char fname1[10],fname2[10],lines[300];
    FILE *fp1,*fp2;
    printf("Enter the source file name: ");
    scanf("%s",fname1);
    printf("\nEnter the destination file name: ");
    scanf("%s",fname2);
    fp1=fopen(fname1,"r+");
    fp2=fopen(fname2,"r+");
    if(fp1==NULL||fp2==NULL)
    {
        printf("\nCan't open file");
        return 1;
    }
    while(fgets(lines,sizeof(lines),fp1)!=NULL)
    {
        fprintf(fp2,"%s",lines);
    }
    printf("\nSuccess");
    fclose(fp1);
    fclose(fp2);
}