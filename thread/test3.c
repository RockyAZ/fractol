/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:22:26 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/19 16:22:31 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Let us create a global variable to change it in threads
int g = 0;

// The function to be executed by all threads
void *myThreadFun(void *vargp)
{
	// Store the value argument passed to this thread
	int *myid = (int *)vargp;

	// Let us create a static variable to observe its changes
	static int s = 0;

	// Change static and global variables
	++s; ++g;
for(int j = 0; j < 2000000; j++)
	;
	// Print the argument, static and global variables
	printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, s, g);
	return 0;
}

int main()
{
	int i = 0;
	pthread_t tid;

	// Let us create three threads
	while (i < 10)
	{
		pthread_create(&tid, NULL, myThreadFun, (void*)&i);
		printf("=====================\n");
		i++;
	}
//		pthread_join(tid, NULL);	
	pthread_exit(NULL);

	printf("////////////////////////////\n");
//		pthread_create(&tid, NULL, myThreadFun, (void *)&i);
//		pthread_create(&tid, NULL, myThreadFun, (void *)&i);
//		pthread_create(&tid, NULL, myThreadFun, (void *)&i);
	return 0;
}
