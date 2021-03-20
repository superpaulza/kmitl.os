#include <stdlib.h> //for atoi()
#include <unistd.h> //for pipe
#include <wait.h>   //for wait()
#include <string.h> //for strcpy()
#define SIZE 10     //pipe buffer size
#include <stdio.h>

int main() {
  int pfd[2];	//storing (pipe) file descriptor
  			      //returned from pipe()
  int nread;    //number of bytes read from sender
  int pid; 	//pid_t is actually an int type
  char buf[SIZE];
  char inbuf[SIZE*2];
  pipe(pfd); //ans1.1
  //if (pipe(pfd) == -1)       
    //{perror("pipe failed\n"); exit(-1);}
  printf("write file id = %d. read file id = %d\n",pfd[1], pfd[0]);

  pid = fork(); //ans1.2
  //if ((pid = fork()) < 0) 
         //{perror("pipe failed\n"); exit(-1);}
  if (pid == 0) {   //child
    close(pfd[1]);  //tidy unused end (ans1.3)	
    //read until end of stream
    while ((nread = read(pfd[0], buf , SIZE)) != 0) 
      if (nread > 11)
            printf("avoid overflow no convertion %s.\n",buf);
      else printf("child received %s. + 5 = %d\n", 
                     buf,atoi(buf)+5);    
      close(pfd[0]); //properly close unused resource
  } else {
    close(pfd[0]);  //tidy unused end (ans1.6)
    
    //strcpy(inbuf,"1200"); //equiv "1200\0"
    sprintf(inbuf,"%ld",123456789012); 
    //a more graceful way to convert long int to string
    write(pfd[1], inbuf, SIZE*2 );	      
    //+1 for padding end of string character (\0)
    printf("sending %ld characters\n", strlen(inbuf)+1);

    close(pfd[1]);  wait(NULL);            
    //close and wait for child to complete    
  }
  return 0;  
} //main
