/* Program demonstrates the use of kill() */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int notDone = 1; int cnt = 0;
void mySIGhandler(int sig) {
   signal(SIGALRM, SIG_IGN);
   //breaks infinite loop by reset notDone
   notDone = 0;
   printf("loop should break\n"); 
}
int main(void) {
  //install handler
   signal(SIGALRM, mySIGhandler);
   pid_t pid = fork();
   if (pid == 0) {
      printf("child created\n");
      while(1); //infinte loop
      printf("this line should not be shown");
      exit(0); // send signal and die
      } else {
          sleep(4);
          if (notDone) kill(getpid(),SIGALRM); 
      }
    //Could be time instead of cnt
    //printf("it takes %d\n",cnt);
     return 0;
} //main
