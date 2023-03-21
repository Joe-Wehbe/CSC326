/*
NAME: Joe Wehbe                                                         
ID#: 202000908                                                                 
COURSE: Operating Systems (CSC326)                                
DATE LAST MODIFIED: 10/09/2022                                               
PROGRAM DESCRIPTION: program that implements a ”special Reverse” Ceasar Cipher.
*/

#include <stdio.h>

int main() {
    
    printf("Please enter the text you would like to cypher: \n");
    char word[20];
    gets(word);
    
    char temp[20];
    strncpy(temp, word, 20);

    printf("Please enter N the number of integers in the list: \n");
    int size;
    scanf("%d", &size);
    
    int keys[size];
    int repeatedKeys[strlen(word)];
    int key;
    
    printf("Please enter the %d integers: \n", size);
    for(int i = 0; i < size; i++){
        scanf("%d", &key);
        keys[i] = key;
    }
    
    int i = 0;
    for(int j = 0; j < strlen(word); j++){
        int finalKey = (keys[i] * (j+1)) % 26;
        repeatedKeys[j] = finalKey;
        i++;
        if (i == size){
            i = 0;
        }
    }
    int j = 0;
    for (int k = strlen(word) - 1; k >= 0; --k) { 
         int ascii = (int)word[k];
         int cypher = ascii+repeatedKeys[j];
            
         if (cypher > 122){
             cypher = cypher - 26;
         }
         if (cypher < 97){
             cypher = cypher + 26;
         }
            
        char c = cypher;
        printf("Letter: %c          Key: %d", word[k], repeatedKeys[j]);
        word[k] = c;
        printf("            Cypher: %c\n", c);
         
        j++;
     }
    printf("The text is: %s\n", temp);
    printf("The cyphered text is: ");
    for(int i = strlen(word) - 1; i >= 0; --i){
        printf("%c",word[i]);
    }

    return 0;
}