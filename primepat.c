#include <stdio.h>

  
int main() {
  int arr[15]={1,2,3,5,7,11,13,17,19,23};
  int i,j,n;
  printf("enter the number:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  for(j=0;j<i;j++)
  {
  printf("%d ",arr[j]);
  }printf("\n");
  }
}