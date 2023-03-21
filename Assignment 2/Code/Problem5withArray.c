#include <stdio.h>
#include <stdbool.h>

int main(){
    
    int num;
    
    printf("Please enter N the number of integers in the list:\n");
    scanf("%d", &num);
    
    int array[num];
    
    bool flag = false;

    printf("Please enter the %d integers: \n", num);
    
    for (int i = 0; i < num; ++i){
        scanf ("%d", &array[i]);
    }
        
    for(int j = 0; j< num; j++){
        for(int k = j+1; k < num; k++){
            for(int l = j+2; l < num; l++){
                for(int m = j+3; m < num; m++){
                    
                    if(array[j] % 5 == 0&&array[k] % 5 == 0 && array[l] % 5 == 0 && array[m] % 5 == 0){
                        flag = true;
            
                    }else{
                        flag = false;
                    }
                  
                }
            }
        }
    }
     
    if(flag){
        printf("Four consecutive integers multiple of 5? YES");
    }else{
        printf("Four consecutive integers multiple of 5? NO");
    }
  
}