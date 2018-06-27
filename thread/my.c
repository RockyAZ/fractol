#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;

void* trythis(void *arg)
{
	pthread_mutex_lock(&mutex);
	static int counter;
	int *i = malloc(4);
	i = (int*)arg;
	pthread_mutex_unlock(&mutex);
//	sleep(1);

	counter++;
	printf("Job %d has started\nI::%d\n", counter, *i);
//	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main(void)
{
	int i = 0;
	int error;
	pthread_t tid[10];

	pthread_mutex_init(&mutex, NULL);
	while(i < 10)
	{
		pthread_create(&(tid[i]), NULL, &trythis, (void*)&i);
		i++;
	}
//	i = 0;
//	printf("111111\n");
//	printf("222222\n");
	i = 0;
	while (i < 10)
		pthread_join(tid[i++], NULL);
	printf("FIIIIIIINISH\n");
	return 0;
}