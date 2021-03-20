//we won't pipe for now
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main() {
  FILE *file_desc = fopen("aaa.txt","w"); //"w" for write mode
  int fd = fileno(file_desc);  //obtain file descriptor
  printf("current file descriptor is %d\n",fd);

  // after mapping to stdout, texts to be displayed 
  // will be redirected to aaa.txt instead 

  // ans2.1
  dup2(fd, 1);
  /* a */
  printf("hi from q2\n");

  close(fd);
  return 0;
}
