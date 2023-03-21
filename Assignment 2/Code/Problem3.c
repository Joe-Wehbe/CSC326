#include <stdio.h>
#include <math.h>

void Modify(int *);

int main (){
    
    int x;
    
    printf("Please enter an integer x:\n");
    scanf("%d", &x);
    
    printf("Before ==> x= %d \n", x);
    Modify(&x);
    printf("After ==> x= %d \n", x);
}

void Modify(int *x){
    *x = pow(*x, 3);
}