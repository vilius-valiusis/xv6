#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
  if(argc < 3){
    printf(2, "mv: oldname newname");
    exit();
  }
  if(link(argv[1],argv[2]) < 0){
    printf(2,"Failed to %s link with %s\n",argv[1],argv[2]);
    exit();
  }

  if(unlink(argv[1]) < 0){
    printf(2,"Failed to unlink %s\n",argv[1]);
    exit();
  }
  exit();
}
