#include<stdio.h>
#include<string.h>
void main()
{
    int i, j;
    char array[100] = "oii2 hello1 vanakam3";
    char td_array[3][100];
    char arrange[3][100];
    char *str = strtok(array, " "); //tokanization
    i=0;
    while(str != NULL)
    {
        strcpy(td_array[i], str);
        str = strtok(NULL, " ");
        i++;
    }
    for(i = 0; i < 3; i++)
    {
        int min_index = i;
        for(j = i + 1; j < 3; j++)
        {
            int one = td_array[i][strlen(td_array[i]) - 1] - '0';
            int two = td_array[j][strlen(td_array[j]) - 1] - '0';
            
            if (two < one)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            strcpy(arrange[i], td_array[min_index]);
            //strcpy(td_array[min_index], td_array[i]);
        }
        else
        {
            strcpy(arrange[i], td_array[i]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        printf("%s\n", arrange[i]);
        }
}