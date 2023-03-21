/*
NAME: Joe Wehbe                                                         
ID#: 202000908                                                                 
COURSE: Operating Systems (CSC326)                                
DATE LAST MODIFIED: 10/09/2022                                               
PROGRAM DESCRIPTION: program that implements a temperature struct where the user can change the temperature or get it in celcius/fahrenheit.
*/

#include <stdio.h>

typedef struct temperature{
    float temp;
    char degree;
    
}temperature;
    
void ChangeTemp(struct temperature *T, float t, char d){
        
    T->temp = t;
    T->degree = d;
        
        printf("Temperature changed to: %.1f%c \n", T->temp, T->degree);
}

float getCelsius(struct temperature *T){
    if (T->degree == 'C'){
        return T->temp;
    }
    return (T->temp - 32)/1.8;
}


float getFahren(struct temperature *T){
    if (T->degree == 'F'){
        return T->temp;
    }
    return 1.8*T->temp + 32;

}


int main() {
    
    struct temperature t;
    struct temperature *t1 = &t;
    
    float tmp;
    printf("Enter the temperature: ");
    scanf(" %f", &tmp);
    
    char d;
    while (d != 'F' && d != 'C' && d != 'f' && d != 'c'){
        printf("Enter the degree (C = Celsius, F = Fahrenheit): ");
        scanf(" %c", &d);
    }
    d = toupper(d);
    ChangeTemp(t1, tmp, d);
    printf("Temperature in celsius: %.1fC \n", getCelsius(t1));
    printf("Temperature in fahrenheit: %.1fF", getFahren(t1));

   
    
        
    return 0;
}