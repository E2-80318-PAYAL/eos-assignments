#include<stdio.h>
#include<fcntl.h> //for dupe
#include<unistd.h> //read,write,pipe isko include krne ke liye
#include<sys/wait.h>

int main(){
    int ret,err,s,fd;
    printf("program started . \n");
    ret = fork();
    if(ret == 0){
        //input redirection
        fd = open("in.txt", O_CREAT | O_RDONLY , 0664);
        close(0);
        dup(fd);
        close(fd);

        err = execlp("wc","wc",NULL); //wc-word count  (I am student ! --> wc= 1  4 15 = line,words,no of letters)
        if(err < 0){
            perror("exec() failed");
            _exit(1);
        }
    }
    else
        waitpid(ret, &s, 0);
        printf("program compled.\n");
        return 0;
}
