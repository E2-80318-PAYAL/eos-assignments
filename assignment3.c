
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid ,count = 0;

    while(1) {
        pid = fork();
        if(pid == -1)
            {
                perror("fork");
                break;
            }
        else if(pid == 0) {
            // child process
            _exit(0);
        }
        else {
            // parent process
            count++;
            printf("created child process %d with PID %d\n",count,getpid());
        }
    }
    
    //printf("max child count: %d\n", count);

    printf("maximum no of child processes reached \n");
    return 0;
}