#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

//parent A -> child B -> child C -> child D
int main(){
    int i, pidb,sb,pidc,sc,pidd,sd;

    //parent a
    pidb = fork();
    if(pidb == 0){
        //child b
        pidc = fork();
        if(pidc == 0){
            //child c
            pidd = fork();
            if(pidd == 0){
                //child d
                for (i = 1; i <=5; i++)
                {
                    printf("D. sunbeam dac: %d, PID = %d, PPID = %d\n",i,getpid(),getppid());
                    sleep(3);
                }
                _exit(0);
                
            }
            for(i=1;i<=5;i++){
                printf("C. sunbeam desd: %d, PID = %d, PPID = %d\n",i,getpid(),getppid());
                sleep(3);
            }
            _exit(0);

        }
        //child b
        for (i = 1; i <=5; i++)
        {
            printf("B. sunbeam pune: %d, PID = %d, PPID = %d\n",i,getpid(),getppid());
            sleep(3);
        }
        waitpid(pidc,&sc,0);
        _exit(0);
        
    }




    //parent A
    for (i = 1; i <=5; i++)
    {
        printf("A. Sunbeam: %d, PID = %d, PPID = %d\n",i,getpid(),getppid());
        sleep(3);
    }
    waitpid(pidb,&sb,0);
    
    return 0;
}