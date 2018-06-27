/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 13:39:19 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/21 13:39:20 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*thread_julia(void *wi)
{
	t_mandel	man;
	t_thread	*thr;
	int			i;
	int			x;
	int			y;

	thr = (t_thread*)wi;
	y = thr->y;
	while (y < thr->lim_y)
	{
		x = 0;
		while (x < WIDTH)
		{
			man.rn[1] = 1.5 * (x - WIDTH / 2) / (0.5 * thr->zoom * WIDTH) + thr->move_x;
			man.in[1] = (y - HEIGHT / 2) / (0.5 * thr->zoom * HEIGHT) + thr->move_y;
			i = 0;
			while (i < thr->iter)
			{
				man.rn[0] = man.rn[1];
				man.in[0] = man.in[1];
				man.rn[1] = ((man.rn[0] * man.rn[0]) - (man.in[0] * man.in[0])) + thr->buf_r;
				man.in[1] = 2 * man.rn[0] * man.in[0] + thr->buf_i;
				if ((man.rn[1] * man.rn[1] + man.in[1] * man.in[1]) > 4)
					break ;
				i++;
			}
			set_pixel(x, y, i, thr);
			x++;
		}
		y++;
	}
	return (0);
}

void	julia(t_win *win)
{
	int i;
	pthread_t tid[THREAD];

	i = 0;
	while (i < THREAD)
	{
		pthread_create(&tid[i], NULL, &thread_julia, &win->thread[i]);
		i++;
	}
	i = 0;
	while (i < THREAD)
		pthread_join(tid[i++], NULL);
	drawing(win);
}