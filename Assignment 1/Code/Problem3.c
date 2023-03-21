#include <stdio.h>

float a=3, b=8, c=5;

float average(){
    float average = (a+b+c)/3;
    return average;
}

int main() {
    
    printf("The average is %.2f",average());
    
    return 0;
}