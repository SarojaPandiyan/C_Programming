//(2,4,1,5,7,3)=(7,1),(5,2),(4,3)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void Pair(int arr[],int size)
{
    int lar=arr[0];
    int small=arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i]>lar)
            lar=arr[i];
        if(arr[i]<small)
            small=arr[i];
    }
    printf("(%d,%d)\n",lar,small);
    
    int arr1[size-2];
    int c=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==lar || arr[i]==small)
            continue;
        else
        {arr1[c]=arr[i];
         c++;
        }
    }
    size-=2;
    if(size>0)
    {
        Pair(arr1,size);
    }

}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int s;
    scanf("%d",&s);
    int arr[s];
    for(int i=0;i<s;i++)
    {
        scanf("%d",&arr[i]);
    }
    Pair(arr,s);
    return 0;
}
