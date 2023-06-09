#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  if(argc != 2 ){
    fprintf(2, "usage: argv numbers is error\n");
    exit(1);
  }
  int ticks = atoi(argv[1]);
  if(ticks == 0 && strcmp(argv[1],"0")!=0){
    fprintf(2, "sleep: invalid time interval '%s'\n", argv[1]);
    exit(2);
  }
  sleep(ticks);

  exit(0);
}