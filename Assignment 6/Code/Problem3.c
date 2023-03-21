#define _GNU_SOURCE

#include<sys/wait.h>
#include<sys/types.h>
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/mman.h>
#include <string.h>


void printArray(int *array, int N){
    for(int i=0;i<N; i++){
        printf("%d ",array[i]);
    }   
}

int main(){
  
      int N;
      printf("Please enter the size of the array:\n");
      scanf("%d",&N);
    
    int * shared_arr= (int *) mmap(NULL, sizeof(int) * N, PROT_READ |PROT_WRITE, MAP_SHARED |MAP_ANONYMOUS, -1,0);
    
    if (shared_arr == MAP_FAILED){
        perror ("MAPING FAILED");
        exit(EXIT_FAILURE);
    }
                
    pid_t child1=fork();
    
    if (child1<0)
    {
        perror("CHILD1 FORKING ERROR");
        exit(1);
    }
    else{
        if(child1==0){
            pid_t child3= fork();
            
            if (child3<0){
                perror("CHILD3 FORKING ERROR");
                exit(1);
            }
            else{
                if (child3==0){
                printf("*** From Child 3: ***\n");
                printf("Please enter %d integers: \n", N);
                for (int i=0; i<N; i++)
                    scanf("%d", &shared_arr[i]);
                
                printArray(shared_arr,N);
                }
                else{
                    wait(NULL);
                    printf("\n*** From Child 1: ***\n");
                    for (int i=0; i<N; i++)
                    shared_arr[i]=shared_arr[i]*10;
                    printArray(shared_arr,N);
                    printf("\n");
                }
            }
            
            
        }
        else{
            wait(NULL);
            
            pid_t child2= fork();
            
            if (child2<0) {
                perror("Failed Fork Child2");
                exit(1);
            }
            else{
                if (child2==0){
                    printf("*** From Child 2: ***\n");
                    for (int i=0; i<N; i++)
                    shared_arr[i]=shared_arr[i]-2;
                
                    printArray(shared_arr,N);                    
                }
                else {
                    wait(NULL);
                    printf("\n*** From Parent: ***\n");
                         
                    shared_arr= mremap(shared_arr,sizeof(int) * N, (N+1)* sizeof(int),0);
                           
                    int sum=0;
                    for (int i=0; i<N; i++){
                        sum += shared_arr[i];
                    }
                          
                    shared_arr[N]=sum;
                    printArray(shared_arr,N+1);
                }
            }
                
        }
    
    }
    
     munmap(shared_arr, sizeof(int) *N);
    
    return 0;
}


