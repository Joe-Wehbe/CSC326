#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    
    int pid = getpid();
    int ppid = getppid();
    
    printf("Main Process PID = %d, PPID = %d\n", pid, ppid);
    
    int id = fork();

    if (id < 0){
        printf("An error has occured.");
        exit(0);
    }
    else{
        if(id == 0){
            printf("Child Process PID = %d, PPID = %d\n", getpid(), getppid());
            execlp("date", (char*) NULL);

        }else{
            int wstatus;
            wait(&wstatus);
            printf("Parent Process PID = %d, child PID = %d, PPID = %d\n", pid, getpid()+1, ppid);
            
            if (WIFEXITED(wstatus)){
                int status = WEXITSTATUS(wstatus);
                if(status == 0){
                    printf("Child exit code = %d\n", status);
                    printf("Child succeeded!\n");
                }else{
                    printf("Child exit code = %d\n", status);
                    printf("Child failed!");
                }
            }
            
           
        }

    }
    


    return 0;
}