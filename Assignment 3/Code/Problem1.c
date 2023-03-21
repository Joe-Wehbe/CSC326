/*
NAME: Joe Wehbe                                                         
ID#: 202000908                                                                 
COURSE: Operating Systems (CSC326)                                
DATE LAST MODIFIED: 10/09/2022                                               
PROGRAM DESCRIPTION: program that counts the number of letters, uppercase letters, lowercase letters, integers, and special characters of a given string.
*/

#include <stdio.h>

int main() {
    
    printf("Please enter a string: ");
    char str[20];
    gets(str);

    int letterCount = 0;
    int lowerCount = 0;
    int upperCount = 0;
    int intCount = 0;
    int specialCount = 0;

    size_t i = 0;

    while (str[i] != '\0') { 
        int ascii = (int)str[i];
        
        if (ascii >= 97 && ascii <= 122){
            letterCount++;
            lowerCount++;
            
         }else if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9'){
             intCount++;
            
        }else if (ascii <= 97 || ascii >=122) {
            if (ascii <= 65 || ascii >= 90){
                specialCount++;

            }else{
                letterCount++;
                upperCount++;
            }
        }
        i++;
    }
    printf("The number of letters is: %d\n", letterCount);
    printf("The number of uppercase letters is: %d\n", upperCount);
    printf("The number of lowercase letters is: %d\n", lowerCount);
    printf("The number of integers is: %d\n", intCount);
    printf("The number of special characters is: %d\n", specialCount);

    return 0;
    
    
}