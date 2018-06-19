/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:58:06 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/19 16:01:11 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/* This is our thread function.  It is like main(), but for a thread*/
void *threadFunc(void *arg)
{
	char *str;
	int i = 0;

	str=(char*)arg;

	while(i < 10)
	{
		usleep(100000);
		printf("\e[1;34mthreadFunc says: %s\n",str);
		++i;
	}

	return NULL;
}

int main(void)
{
	pthread_t pth;// this is our thread identifier
	int i = 0;

	pthread_create(&pth,NULL,threadFunc,"foo");

	while(i < 10)
	{
		usleep(100000);
		printf("\e[1;35mmain is running...\n");
		++i;
	}

	printf("\e[1;31mmain waiting for thread to terminate...\n");
	pthread_join(pth,NULL);

	return 0;
}
