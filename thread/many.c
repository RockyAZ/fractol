/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:25:53 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/21 17:25:53 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAXTHREADS 1000000
#define THREADSTACK  65536
#include <pthread.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pthread_t       pid[MAXTHREADS];
    pthread_attr_t  attrs;
    int  err, i;
    int  cnt = 0;

    pthread_attr_init(&attrs);
    pthread_attr_setstacksize(&attrs, THREADSTACK);

    pthread_mutex_init(&mutex_, NULL);

    for (cnt = 0; cnt < MAXTHREADS; cnt++) {

        err = pthread_create(&pid[cnt], &attrs, (void*)inc_thread_nr, NULL);
        if (err != 0)
            break;
    }

    pthread_attr_destroy(&attrs);

    for (i = 0; i < cnt; i++)
        pthread_join(pid[i], NULL);

    pthread_mutex_destroy(&mutex_);

    printf("Maximum number of threads per process is %d (%d)\n", cnt, thread_nr);
}