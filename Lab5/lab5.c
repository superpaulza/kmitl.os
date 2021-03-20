#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
	pid_t cpid;
	pid_t gcpid;

	/* fork another process */
	cpid = fork();
	/* if (cpid < 0) { //error occurred
	fprintf(stderr, "Fork Failed");	exit(-1);
	} else { */
		if (cpid == 0) { /* child procress */
			gcpid = fork();
				if (gcpid == 0) { //grandchild
				printf("Can you see this3?\n");
				exit(0);
				}
			execlp("/bin/lssdd", "ls", NULL); /* A */
			printf("Can you see this2?\n"); /* B */
		}	
	/*} if error */
		//else {
			printf("Can you see this1?\n"); /* C */
			wait(NULL); printf("received Child complete\n");
			exit(0);
		//}
	return 0;
} //main


