#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
//Parent process
	pid_t cmd;
	char userChoice = 'z';
	while (userChoice != 'q') {
		//print menu
		printf("a: ls \n");
		printf("b: ps \n");
		printf("c: who \n");
		printf("q for quit \n");
		scanf(" %c", &userChoice);
		//need code 1
		cmd = fork();
		if (cmd == 0) {
			switch (userChoice)
			{
				case 'a':
					execlp("/bin/ls", "ls", NULL);
					printf("Error! The ls cmd is\'t exist!\n");
					exit(0);	
					break;
				case 'b':
					execlp("/bin/ps", "ps", NULL);
					printf("Error! The ps cmd is\'t exist!\n");
					exit(0);
					break;
				case 'c':
					execlp("usr/bin/whoami", "whoami", NULL);
					printf("Error! The who cmd is\'t exist!\n");
					exit(0);
					break;
				default:
					exit(0);
					break;
					
			}
		}
		//need code 2
		wait(NULL);
	} //while
	printf("parent terminated\n");
}


/*int main() {
	pid_t cmd;
	char userChoice = 'z';
	while (userChoice != 'q') {
	//print menu
		printf("a: ls \n");
		printf("b: ps \n");
		printf("c: who \n");
		printf("q for quit \n");
		scanf(" %c", &userChoice);
		//need code 1
		cmd = fork();
		if (cmd == 0) { // child begin
			//perform ls
			if (userChoice == 'a') {
				execlp("/bin/ls", "ls", NULL);
				printf("Error! The ls cmd is\'t exist!\n");
				exit(0);
			}
			//perform ps
			if (userChoice == 'b') {
				execlp("/bin/ps", "ps", NULL);
				printf("Error! The ps cmd is\'t exist!\n");
				exit(0);			
			}
			//perform who
			if (userChoice == 'c') {
				execlp("/usr/bin/who", "who", NULL);
				printf("Error! The who cmd is\'t exist!\n");
				exit(0);			
			}
			else {
				exit(0);
			}
		}
		//need code 2
		wait(NULL);
	} //while
	printf("parent terminated\n");
}*/