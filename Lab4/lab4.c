#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<time.h> 

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

int q1() {
    pid_t pid;
    int i = 0; //prevent garbage

    pid = fork();
    if(pid > 0) { //parent
        i = 1;
        printf("my copy of i is %d\n", i);
    } else { //child
        i = 2;
        printf("my copy of i is %d\n",i);
    }

    return 0;
}

int q2(void) {
    pid_t pid;
    int i;

    pid = fork();
    if(pid > 0) { //parent
        i = 1;
        printf("my copy of i is %d\n", i);
    } else { //child
        i = 2;
        printf("my copy of i is %d\n",i);
    }
    wait(NULL);
    return 0;    
}

int q3_1(void) {
    pid_t pid;
    int i; int sum = 3;

    pid = fork();
    if(pid > 0) { //parent
        i = 1; sum += i;
        printf("my copy of i is %d\n", i);
    } else { //child
        i = 2; sum += i;
        printf("my copy of i is %d\n",i);
    }
    printf("my sum = %d\n", sum);
    wait(NULL);
    return 0;      
}

int q3_2(void) {
    pid_t pid;
    int i; int sum = 3;
    for (i = 0; i < 3; i++)
    {
        pid = fork();
        if (pid == 0) { //child
            printf("my copy of i is %d\n",i);
            //exit(0);
            printf("should not be executed\n");
        }
    }
    
    
    while (wait(NULL) != -1);
    printf("bye from main = %d\n", sum);
    return 0;      
}

int q4_5() {
	pid_t pid;
	int i, sum = 0;
	if ((pid = fork()) > 0) {
		i = 1;
		sum += i;
		printf("I am parent. My id is %d\n", getpid());
	} else {
		i = 2;
		sum += i;
		printf("I am child. My id is %d\n", getpid());
		printf("My parent id is %d\n", getpid());
		exit(0);
	}

	wait(NULL);
	printf("(parent) sum = %d\n", sum);
	return 0;
}

int q4_7() {
	pid_t pid;
	int i = 0, sum = 0, num = 0;
	printf("Enter a positive number: ");
	scanf("%d", &num); //num = getchar() - 48; while(getchar() != '\n');
	if (num <= 0) {
		printf("You did not enter a positive number\n");
		exit(1); //exit(-1)
	}
	if (pid = fork() > 0 ) { //parent
		for ( i = 1; i <= num; i++)
			sum += i;
		wait(NULL);
		printf("I am parent my sum = %d\n", sum);
	} else {
		for ( i = 1; i <= 2 * num; i++)
			sum += i;
		printf("I am child my sum = %d\n", sum);
	}
	return 0;
}

int main(/* int argv, char** argc */) {
    //q1();
    //q2();
    //q3_1();
    //q3_2();
    //q4_5();
    q4_7();
}
