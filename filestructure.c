#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct 
{
    char Name[30];
    int reg_num,class;
}student;
void getDetails(student* st,int size)
{
    int i;
    for(i=0;i<3;i++)
    {
        printf("Enter the student name: ");
        fgets(st[i].Name,sizeof(st[i].Name),stdin);
        st[i].Name[strcspn(st[i].Name,"\n")]='\0';
        printf("Enter the register number: ");
        scanf("%d",&st[i].reg_num);
        getchar();
        printf("Enter the class: ");
        scanf("%d",&st[i].class);
        getchar();
    }
}

void main()
{
    int i;
    char line[100],*token;
    FILE *fp;
    student st[3],ret_st[3];
    getDetails(st,3);
    fp=fopen("file.txt","w+");
    if(fp==NULL)
    {
        printf("\nCan't open the file");
    }
    for(i=0;i<3;i++)
    {
        fprintf(fp,"%s\t",st[i].Name);
        fprintf(fp,"%d\t",st[i].reg_num);
        fprintf(fp,"%d\n",st[i].class);
    }
    fclose(fp);
    fp=fopen("file.txt","w+");
    {
        i=0;
        while(fgets(line,sizeof(line),fp)!=NULL)
        {
           
            sscanf(line,"%[^\t] %d %d",ret_st[i].Name,&ret_st[i].reg_num,&ret_st[i].class);
            i++;
        }
        for(i=0;i<3;i++)
        {
            printf("\n%s,%d,%d",ret_st[i].Name,ret_st[i].reg_num,ret_st[i].class);
        }
    }
    fclose(fp);}

