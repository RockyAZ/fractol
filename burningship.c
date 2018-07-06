/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 19:33:12 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/28 19:33:12 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*thread_burningship(void *wi)
{write(1, "b\n",2);
	t_burning	bur;
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
			bur.z[0] = 1.5 * (x - WIDTH / 2) / (0.5 * thr->zoom * WIDTH) + thr->move_x;
			bur.z[1] = (y - HEIGHT / 2) / (0.5 * thr->zoom * HEIGHT) + thr->move_y;
			bur.c[0] = bur.z[0];
			bur.c[1] = bur.z[1];
			i = 0;
			while (i < thr->iter)
			{
				bur.z[0] = fabs(bur.z[0]);
				bur.z[1] = fabs(bur.z[1]);
				bur.temp[0] = bur.z[0] * bur.z[0] - bur.z[1] * bur.z[1] + bur.c[0];
				bur.temp[1] = bur.z[0] * bur.z[1] * 2 + bur.c[1];
				if (bur.z[0] * bur.z[0] + bur.z[1] * bur.z[1] > 4)
					break ;
				bur.z[0] = bur.temp[0];
				bur.z[1] = bur.temp[1];				
				i++;
			}
			set_pixel(x, y, i, thr);
			x++;
		}
		y++;
	}
	return (0);
}

void	burningship(t_win *win)
{
	int i;
	pthread_t tid[THREAD];

	i = 0;
	prepare_draw(win);
	while (i < THREAD)
	{
		pthread_create(&tid[i], NULL, &thread_burningship, &win->thread[i]);
		i++;
	}
	i = 0;
	while (i < THREAD)
		pthread_join(tid[i++], NULL);
	drawing(win);
}
