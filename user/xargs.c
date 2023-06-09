#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"
#define MAXLEN 32
int main(int argc,char* argv[]){
    char buffer[MAXLEN*MAXARG]={0},*p=0;
    char *params[MAXARG];
    int params_num=0;
    char* path = "echo";
    
    if(argc>1){
        if(argc+1>MAXARG){
            printf("too many ars\n");
            exit(1);
        }
        path = argv[1];
        for(int i=1;i<argc;++i){
            params[params_num++]=argv[i];
        }

    }else{
        params[params_num++] = path;
    }
    p = buffer;
    while(1){
        int len;
        while(1){
            len = read(0,p,1);
            if(len==0||*p=='\n'){
                break;
            }
            ++p;
        }
        if(len == 0)break;
        *p = 0;
        params[params_num]=buffer;
        if(fork()==0){
            exec(path,params);
            printf("exec failed\n");
            exit(1);
        }else{
            wait((int*)0);
            p = buffer;
        }

    }
    exit(0);
}