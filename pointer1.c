#include<stdio.h>
void main()
{
int x =5; 
char c = 'a'; 
int *p = &x; 
char *ch = &c;
printf("%d\n",*p);
printf("%c \t %d\n", *ch, *ch);
p++;
ch++;
printf("%d\n", *p);
printf("%c\n", *ch);
(*p)++;
(*ch)++;
printf("%d\n", *p);
printf("%c\n", *ch);
p--;
ch--;
printf("%d\n", *p);
printf("%c\n", *ch);
printf("%p\t", p); 
printf("%p\t", &p); 
printf("%p\n",&x);
printf("%p\t",ch); 
printf("%p\t",&ch);
printf("%p\n",&c);
} 