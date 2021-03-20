#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *runner(void *param); //prototye

int num = 0; //global
int csum = 0; //global

int main(int argc, char *argv[]) {
	num = atoi(argv[1]);
	int msum = 0;
	pthread_t tid;
	pthread_attr_t attr;

	pthread_attr_init(&attr);						/* create the thread */
	pthread_create(&tid, &attr, runner, argv[1]);	/* thread call function runner */
	
	

	printf("I am mother thread, I will wait for my child thread\n");
	//pthread_join(tid, NULL);
	
	for (int i = 1; i <= num; i++) msum += i;
	printf("I am mother thread, i value here is %d\n", msum);

	printf("Different of csum and msum is %d\n", (csum-msum));
}

/* the thread will begin control in this function */
void *runner (void *param) {
	for (int i = 1; i <= num*2; i++) csum += i;
	printf("I am child thread, i value here is %d\n", csum);
	pthread_exit(0);
}
