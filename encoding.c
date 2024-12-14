//MADRAS-OEFVCW
//Zoo-BSQ odd position=plus 4;even=plaus 2;
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<ctype.h>

int main() {
    char str[30];
    scanf("%s",str);
    int c=0;
    for(int i=0;i<strlen(str);i++)
    {
       if(isalpha(str[i]))
           continue;
        else
        {
            c=1;break;
        }
    }
    char arr[30];
    if(c==0)
    {
        for(int i=0;i<=strlen(str);i++)
        {
            if(i%2!=0)
            {
                if(str[i]>='A' && str[i]<='Z')
                {
               arr[i]=(((str[i]-'A')+4)%26)+'A'; 
                }
                else if(str[i]>='a' &&  str[i]<='z')
                {
                    arr[i]=toupper((((str[i]-'a')+4)%26)+'a');
                }
            }
            else
            {
                if(str[i]>='A' && str[i]<='Z')
                {
               arr[i]=(((str[i]-'A')+2)%26)+'A'; 
                }
                else if(str[i]>='a' &&  str[i]<='z')
                {
                    arr[i]=toupper((((str[i]-'a')+2)%26)+'a');
                }
                
            }
        }
        
        
    }
    printf("%s",arr);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
