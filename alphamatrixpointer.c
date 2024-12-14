//q w
//a s
//z x
//output
//z s
//q w
//a x
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

     int row,col;
    scanf("%d",&row);
    scanf("%d\n",&col);
    char mat[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf(" %c",&mat[i][j]);
        }
    }
    for(int j=0;j<col;j++)
    {
        for( int i=0;i<row;i++)
        {
            for(int k=i+1;k<row;k++)
            if(j%2==0)
            {
                if(mat[i][j]<mat[k][j])
                { char temp=mat[i][j];
                    mat[i][j]=mat[k][j];
                    mat[k][j]=temp;}}
            else
            {
                if(mat[i][j]>mat[k][j])
                { char temp=mat[i][j];
                    mat[i][j]=mat[k][j];
                    mat[k][j]=temp;}
                
            }
                
            }
        }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%c ",mat[i][j]);
        }
        printf("\n");
    }   
    return 0;
}
