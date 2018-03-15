#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
  char buf[512];
  /*Low level file disciptors and number of bytes to read*/
  int fd0,fd1, r;

  if(argc <= 2){
    printf(1, "Function requires two arguments");
    exit();
  }
  if((fd0 = open(argv[1], O_RDONLY)) < 0){
    printf(1,"Cannot open source file %s\n",argv[1] );
    exit();
  }
  if((fd1 = open(argv[2], O_CREATE|O_RDWR)) < 0){
    printf(1,"Cannot open destination file %s\n",argv[1] );
    exit();
  }

  while((r = read(fd0,buf,sizeof(buf))) > 0){
    write(fd1,buf,r);
  }
  close(fd0);
  close(fd1);
  exit();
}
