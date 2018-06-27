#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct s_win
{
	pthread_mutex_t mutex;
}				t_win;


void* trythis(void *arg)
{
	t_win *win;

	win = (t_win*)arg;
	pthread_mutex_lock(&win->mutex);
	static int counter;
//	pthread_mutex_unlock(&win->mutex);
//	sleep(1);

	counter++;
	printf("Job %d has started\n", counter);
//	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main(void)
{
	int i = 0;
	int error;
	t_win win;
	pthread_t tid[10];

	pthread_mutex_init(&win.mutex, NULL);
	while(i < 10)
	{
		pthread_create(&(tid[i]), NULL, &trythis, (void*)&win);
		i++;
	}
	i = 0;
	while (i < 10)
		pthread_join(tid[i++], NULL);
	printf("FIIIIIIINISH\n");
	return 0;
}