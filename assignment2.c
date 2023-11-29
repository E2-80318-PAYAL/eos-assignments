#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include<signal.h>

void sigint_handler(int sig) { //ctrl+c -> interrupt dila , siginit la call jail, ani tya mude je current process suru ahe ti intruupt hote, mhnun qs mde mhntl ki ctrl=c ne terminate nahi zal pahej mhnun mi function lihil ani print kel jvha interrupt aal tvha kay print hoil 
    printf("signal caught: %d\n", sig);
}

int main() {
    signal(SIGINT, sigint_handler); // signal interrupt aala ani tyala interrupt vector table mdhe register kel 
    char *ptr, cmd[512], *args[32];
    int i, ret, err, s;
    while(1) {
        printf("cmd> ");
        gets(cmd); // e.g. ls -l -a /home
        
        i=0;
        ptr = strtok(cmd, " ");
        args[i] = ptr;
        i++;
        do {
            ptr = strtok(NULL, " ");
            args[i] = ptr;
            i++;
        } while(ptr != NULL);

        if(strcmp(args[0], "exit") == 0)
            _exit(0); // exit the shell program
        else if(strcmp(args[0], "cd") == 0)
            chdir(args[1]); // change the current directory of the shell program
        else { 
            // execute external command
            ret = fork();
            if(ret == 0) {
                err = execvp(args[0], args);
                if(err < 0) {
                    perror("bad command");
                    _exit(1);
                }
            }
            else
                waitpid(-1, &s, 0);
        }
    }
    return 0;
}