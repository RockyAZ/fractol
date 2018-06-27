/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:03:32 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/26 16:03:33 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

/* This is our thread function.  It is like main(), but for a thread*/
void *threadFunc(void *arg)
{
	char *str;
	int i = 0;

	str=(char*)arg;

	while(i < 10 )
	{
		usleep(1);
		printf("threadFunc says: %s\n",str);
		++i;
	}

	return NULL;
}

int main(void)
{
	pthread_t pth;	// this is our thread identifier
	int i = 0;

	pthread_create(&pth,NULL,threadFunc,"foo");
	
	while(i < 10)
	{
		usleep(1);
		printf("main is running...\n");
		++i;
	}

	printf("main waiting for thread to terminate...\n");
	pthread_join(pth,NULL);

	return 0;
}