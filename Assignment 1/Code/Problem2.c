#include <stdio.h>
#include <math.h>

int main() {
    
    int w = 2;
    int l = 11;
    int r = 5;
    
    int areaRectangle = w*l;
    double areaCircle = M_PI*(r*r);
    
    printf("The area of the rectangle (w=2, l=11) is %d \n",areaRectangle);
    printf("The area of the circle of radius r=5 is %f \n",areaCircle);

    
    return 0;
}