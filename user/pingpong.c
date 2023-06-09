#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int main(int argc,char* argv[]){
    char buffer[1];
    int fd1[2],fd2[2];
    pipe(fd1);
    pipe(fd2);
    if(fork()==0){
        close(fd1[1]);
        read(fd1[0],buffer,1);
        close(fd1[0]);

        int pid = getpid();
        fprintf(1,"%d: received ping\n",pid);

        close(fd2[0]);
        write(fd2[1],buffer,1);
        close(fd2[1]);
        exit(0);
    }else{
        close(fd1[0]);
        write(fd1[1],buffer,1);
        close(fd1[1]);

        close(fd2[1]);
        read(fd2[0],buffer,1);
        close(fd2[0]);

        int pid = getpid();
        fprintf(1,"%d: received pong\n",pid);
        exit(0);
    }

}