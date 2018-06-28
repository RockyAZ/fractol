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
{
	t_julia		jul;
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
			jul.rn[1] = 1.5 * (x - WIDTH / 2) / (0.5 * thr->zoom * WIDTH) + thr->move_x;
			jul.in[1] = (y - HEIGHT / 2) / (0.5 * thr->zoom * HEIGHT) + thr->move_y;
			i = 0;
			while (i < thr->iter)
			{
				jul.rn[0] = jul.rn[1];
				jul.in[0] = jul.in[1];
				jul.rn[1] = ((jul.rn[0] * jul.rn[0]) - (jul.in[0] * jul.in[0])) + thr->buf_r;
				jul.in[1] = 2 * jul.rn[0] * jul.in[0] + thr->buf_i;
				if ((jul.rn[1] * jul.rn[1] + jul.in[1] * jul.in[1]) > 4)
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
