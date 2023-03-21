#include <stdio.h>
#include <stdbool.h>

int main(){
    
    int num;
    int val;
   
    printf("Please enter N the number of integers in the list:\n");
    scanf("%d", &num);
    
    printf("Please enter the %d integers: \n", num);
  
    int count = 0;

    for (int i = 0; i < num; ++i){
        scanf ("%d", &val);
        
        if(val%5 == 0){
            count++;
            continue;
            
        }else{
            continue;
        } 
    }
    
    if(count >= 4){
        printf("Four consecutive integers multiple of 5? YES");
    }else{
        printf("Four consecutive integers multiple of 5? NO");
    }
}