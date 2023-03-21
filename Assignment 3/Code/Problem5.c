/*
NAME: Joe Wehbe                                                         
ID#: 202000908                                                                 
COURSE: Operating Systems (CSC326)                                
DATE LAST MODIFIED: 10/09/2022                                               
*/

#include <stdio.h>

int main() {
    
    int a = 20;
    int *b = &a;
    int c = a;
   
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",*b);
    printf("%d\n",c);
    printf("%d\n",&a);
    printf("%d\n",&b);
    printf("%d\n",&c);
    
    printf("When we update the value of a to 40, a, *b and c will all become 40.");

    return 0;
}