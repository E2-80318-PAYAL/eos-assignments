#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){
    int signum, pid;

    printf("Enter signal num: ");
    //getc(signum);
    scanf("%d",&signum);

    printf("Enter pid number: ");
    //getc(pid);
    scanf("%d",&pid);

    int ret = kill(pid, signum);
}