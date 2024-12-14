//saroja@google.com=saroja   google  com
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str[100];
    scanf("%s",str);
    char *str1=strtok(str,"@");
    int i=0;
    char tdarr[2][50];
    while(str1!=NULL)
    {
      strcpy(tdarr[i],str1);
        str1=strtok(NULL,"@");
        i++;
    }
    char first[30];
    strcpy(first,tdarr[0]);
    i=0;
    char str3[2][20];
    char *str2=strtok(tdarr[1],".");
    while(str2!=NULL)
    {
        strcpy(str3[i],str2);
        str2=strtok(NULL,".");
        i++;
    }
    char second[30];
    strcpy(second,str3[0]);
    char third[40];
    strcpy(third,str3[1]);
    printf("%s\n%s\n%s",first,second,third);
    return 0;
}
