/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 19:33:12 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/06 15:28:21 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void*thread_burningship(void *wi)
{
	t_burningbur;
	t_thread*thr;
	inti;
	intx;
	inty;

	thr = (t_thread*)wi;
	y = thr->y;
	while (y < thr->lim_y)
	{
		x = 0;
		while (x < WIDTH)
		{
			// z.r = fabs(z.r);
			// z.i = fabs(z.i);
			// temp.r = z.r * z.r - z.i * z.i + c.r;
			// temp.i = z.r * z.i * 2 + c.i;

			bur.comp_x = 1.5 * (x - WIDTH / 2) / (0.5 * thr->zoom * WIDTH) + thr->move_x;
			bur.comp_y = (y - HEIGHT / 2) / (0.5 * thr->zoom * HEIGHT) + thr->move_y;
			bur.zx = bur.comp_x;
			bur.zy = bur.comp_y;
			i = 0;
			while (i < thr->iter)
			{
				bur.xtemp = bur.zx * bur.zx - bur.zy * bur.zy + bur.comp_x;
				bur.zx = fabs(bur.xtemp);
				bur.zy = fabs(2 * bur.zx * bur.zy) + bur.comp_x;
				if ((bur.zx * bur.zx + bur.zy * bur.zy) > 4)
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

voidburningship(t_win *win)
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
