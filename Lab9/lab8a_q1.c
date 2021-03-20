/*    This is a simple program that illustrates the use of signal handler.  It catches Ctrl-C (Ctrl-C generates SIGINT).      */
#include <stdio.h>
#include <unistd.h>     // for pause
#include <signal.h>
#include <stdlib.h>     // for exit?

void     INThandler(int);     /* prototype  */

void  main(void) {
     signal(SIGINT, INThandler);        
                    /* install Ctrl-C handler  */
     while (1)           /* loop forever and wait */
          pause();       /* cpu can be allocated to others */
} //main
void  INThandler(int sig) {
  /* when an SIGINT is generated,  
  	    start here as installed (declared)  */
  signal(sig, SIG_IGN);   /* disable Ctrl-C */
  printf("Did you hit Ctrl-C?\n    want to quit? [y/n] \n"); /* print something */
  char c;
  //c = getchar(); /* getchar requires to trim \n */
  scanf("%c",&c);
  if (c == 'y' || c == 'Y') /* if y or Y */
     exit(0);    		          
  else
     signal(SIGINT, INThandler);  
     /* reinstall the handler    */
}
