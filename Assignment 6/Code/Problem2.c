#include<sys/types.h>
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include <string.h>


#define ARRAY_LEN 5
#define STR_LEN 20

int main(){
    char ** shared_arr= (char **) mmap(NULL, sizeof(char*) *ARRAY_LEN, PROT_READ |PROT_WRITE, MAP_SHARED |MAP_ANONYMOUS, -1,0);
    
    
    if (shared_arr== MAP_FAILED){
        perror ("Map Failed");
        exit(EXIT_FAILURE);
    }
    
    for (int i=0; i<ARRAY_LEN;i++){
        shared_arr[i]= (char *) mmap(NULL, STR_LEN, PROT_READ |PROT_WRITE, MAP_SHARED |MAP_ANONYMOUS, -1,0);
    
    }
                
    pid_t child= fork();
    
    if (child < 0){
        // error
        perror("Fork Failed...");
        exit(EXIT_FAILURE);
    }

    else{
        if(child==0){
            
            printf("From child: \n");
            for (int i=0; i<ARRAY_LEN;i++)
            {
                printf("Please enter a name %d:\n", i+1);
                fgets(shared_arr[i], STR_LEN, stdin);
            }
        }
        else{
            //Parent
            wait(NULL);
            printf("\nFrom Parent: ");
            
            for (int i=0; i<ARRAY_LEN; i++) {
                printf("\n\n*** String %d ***\n",i+1);
                printf("%s", shared_arr[i]); 
                 char str[70];
                 strcpy (str, shared_arr[i]);
                 int uppercase=0;
                 int lowercase=0;
                 
            
            for (int i=0;i<strlen(str)-1;i++){
            

                if(str[i] >= 'a' && str[i] <= 'z'){
                    lowercase++;  
                }
                       
                if(str[i] >= 'A' && str[i] <= 'Z'){
                    uppercase++;
                }
            
                   
             }
             printf("Length = %d\n", (int)strlen(shared_arr[i])-1);
             printf("The number of uppercase letters is: %d\n",uppercase);
             printf("The number of lowercase letters is: %d\n",lowercase);
                
                 
            }
            
        }
    }
    
    for (int i =0; i<ARRAY_LEN; i++)
         munmap(shared_arr[i], STR_LEN);
 
 
     munmap(shared_arr, ARRAY_LEN * sizeof(char*));

    
    return 0;
}







