//123456=21.....2+1=3
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int Sum(int num){
    int s=0;
    if(num>=0 && num<10)
        return num;
    else
    {
        if (num > 0) {
            int rem = num % 10;
            num = rem + Sum(num / 10);
            s=Sum(num);
    }
        return s;
    }
    
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    scanf("%d",&n);
    int sum=Sum(n);
    printf("%d",sum);
    return 0;
}
