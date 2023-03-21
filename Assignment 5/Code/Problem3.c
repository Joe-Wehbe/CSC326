#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main() {
    
    int pid = getpid();
    int ppid = getppid();
    
    printf("Main Process PID = %d, PPID = %d\n", pid, ppid);
    
    int id = fork();
    
    if(id == 0){
        printf("Child process PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(5);
        printf("Ready to kill my parent!\n");
        kill(pid, SIGINT);
        printf("I am an orphan now\n");
    }
    return 0;
}