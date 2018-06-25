#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t lock;

void* trythis(void *arg)
{
	pthread_mutex_lock(&lock);

	unsigned long i = 0;
	static int counter;

	counter++;
	printf("Job %d has started\n", counter);

	for(i=0; i<(0xFFFFFF);i++);

	printf(" Job %d has finished\n\n", counter);

	pthread_mutex_unlock(&lock);
 
	return NULL;
}

int main(void)
{
	int i = 0;
	int error;
	pthread_t tid[2];


	pthread_mutex_init(&lock, NULL);
	while(i < 10)
	{
		pthread_create(&(tid[i]), NULL, &trythis, NULL);
		i++;
	}
	i = 0;
	while (i < 10)
		pthread_join(tid[i++], NULL);
	pthread_mutex_destroy(&lock); 
	return 0;
}
