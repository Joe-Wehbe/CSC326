/*
NAME: Joe Wehbe                                                         
ID#: 202000908                                                                 
COURSE: Operating Systems (CSC326)                                
DATE LAST MODIFIED: 10/09/2022                                               
PROGRAM DESCRIPTION: program that implements a sphere struct with many functions. 
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct sphere{
    float x;
    float y;
    float z;
    float radius;
}sphere;

void ScaleSphere(struct sphere *s, int a){
    float coordinate;
    float coordinates[3];
        
    printf("Please enter the coordinates of the center of the sphere: \n");
    for (int i = 0; i < 3; i++){
        scanf("%f",&coordinate);
        coordinates[i] = coordinate;
    }
    s->x = coordinates[0];
    s->y = coordinates[1];
    s->z = coordinates[2];
    
    printf("Please enter the radius of the sphere: ");
    scanf("%f", &s->radius);
        
    printf("Sphere 1: O(x = %.2f, y = %.2f, z = %.2f), radius = %.2f \n", s->x, s->y, s->z, s->radius);
    
    s->radius = s->radius*a;
    
    printf("Sphere 1 scaled by 2: O(x = %.2f, y = %.2f, z = %.2f), radius = %.2f \n", s->x, s->y, s->z, s->radius);
}

float ComputeArea(struct sphere *s){
    float area = 4*3.14*pow(s->radius,2);
    return area;
}

float ComputeVolume(struct sphere *s){
    float volume = ((4*3.14)/3)*pow(s->radius,3);
    return volume;
}

bool withinSphere(struct sphere *s, float a, float b, float c){
    
    float w = sqrt(pow((s->x - a),2) + pow((s->y - b),2) + pow((s-> z - c),2));
    float distance = 2*s->radius*asin(w/(2*s->radius));
    
    if(distance <= s->radius){
        return true;
    }
    return false;
}

void MoveSphere(struct sphere *s, float a, float b, float c){
    
    s->x = s->x + a;
    s->y = s->y + b;
    s->z = s->z + c;
    
    printf("Move the sphere by (%.0f, %.0f, %.0f): \n", a, b, c);
    printf("Sphere 1: O(x = %.2f, y = %.2f, z = %.2f), radius = %.2f", s->x, s->y, s->z, s->radius);
}

int main() {
    
    struct sphere sphere;
    struct sphere *sphere1 = &sphere;
    
    ScaleSphere(sphere1, 2);
    printf("Sphere 1 area = %.2f \n", ComputeArea(sphere1));
    printf("Sphere 1 volume = %.2f \n", ComputeVolume(sphere1));
    
    float coordinate;
    float coordinates[3];
    printf("Please enter the coordinates of the point P: \n");
    for (int i = 0; i < 3; i++){
        scanf("%f",&coordinate);
        coordinates[i] = coordinate;
    }
    float a = coordinates[0];
    float b = coordinates[1];
    float c = coordinates[2];
    
    bool location = withinSphere(sphere1, a, b, c);
    
    if(location){
        printf("P(x = %.2f, y = %.2f, z = %.2f) is located inside the sphere \n", a, b, c);
    }else{
        printf("P(x = %.2f, y = %.2f, z = %.2f) is located outside the sphere \n", a, b, c);
    }
    
    MoveSphere(sphere1, 10, 0, 5);


    return 0;
}