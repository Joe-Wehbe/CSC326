#include <stdio.h>
#include <unistd.h>

int main() {
    
    int id = fork();
    if(id == 0){
        int pid = getpid();
        int ppid = getppid();
        printf("Child1 Process PID= %d, PPID=%d\n", pid, ppid);
    }
    else{
        wait(NULL);
        int id1 = fork();
        if(id1 == 0){
            int pid = getpid();
            int ppid = getppid();
            printf("Child2 Process PID= %d, PPID=%d\n", pid, ppid);
        }
        else{
            wait(NULL);
            int id2 = fork();
            if(id2 == 0){
                int pid = getpid();
                int ppid = getppid();
                printf("Child3 Process PID= %d, PPID=%d\n", pid, ppid);
            }
            else{
                wait(NULL);
                int pid = getpid();
                int ppid = getppid();
                printf("Parent Process PID= %d, PPID=%d\n", pid, ppid);
            }
            
        }
        
    }

    return 0;
}