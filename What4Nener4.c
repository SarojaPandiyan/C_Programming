//no of unique characers in the given string
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<ctype.h>

int main() {

    char str[30];
    scanf("%s",str);
    int count=0;
    
    for(int i=0;i<strlen(str);i++)
    {
        int c=0;
        for(int j=i+1;j<strlen(str);j++)
        {
            if(str[i]==(tolower(str[j]))|| str[i]==(toupper(str[j])))
                c++;
        }
        if(c==0)
            count++;
        
        
        
    }
    printf("%d",count);  
    return 0;
}
