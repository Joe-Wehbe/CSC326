#include <stdio.h>
#include <math.h>

int main (){
    
    for(int i=1; i < 30; i++){
        for(int j = i +1; j < 30; j++){
            for(int k = i+2; k < 30; k++){
                
                int A = pow(i, 2);
                int B = pow(j, 2);
                int C = pow(k, 2);
                
                int sum = A + B;
                
                if(sum == C){
                    printf("(%d, %d, %d)\n", i, j, k);

                }
    
            }
        }
    }
}