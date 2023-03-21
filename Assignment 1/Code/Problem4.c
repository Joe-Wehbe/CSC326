#include <stdio.h>
#include <math.h>

float distance(int xA, int yA, int xB, int yB){
    
    float distance = fabs(xA-xB) + fabs(yA-yB);
    
    return distance;
}

int main() {
    
    int xA = 2;
    int yA = 4;
    int xB = 3;
    int yB = 15;
    
    printf("The Manhattan distance between A and B is %.2f",distance(xA, yA, xB, yB));
    
    return 0;
}