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

void	make_bur_first(int x, int y, t_burning *b, t_thread *t)
{
	b->z[0] = 1.5 * (x - WIDTH / 2) / (0.5 * t->zoom * WIDTH) + t->move_x;
	b->z[1] = (y - HEIGHT / 2) / (0.5 * t->zoom * HEIGHT) + t->move_y;
	b->c[0] = b->z[0];
	b->c[1] = b->z[1];
}

int		make_bur_second(t_burning *b)
{
	b->z[0] = fabs(b->z[0]);
	b->z[1] = fabs(b->z[1]);
	b->temp[0] = b->z[0] * b->z[0] - b->z[1] * b->z[1] + b->c[0];
	b->temp[1] = b->z[0] * b->z[1] * 2 + b->c[1];
	if (b->z[0] * b->z[0] + b->z[1] * b->z[1] > 4)
		return (0);
	b->z[0] = b->temp[0];
	b->z[1] = b->temp[1];
	return (1);
}

void	*thread_burningship(void *wi)
{
	t_burning	bur;
	t_thread	*thr;
	int			i;
	int			x;
	int			y;

	thr = (t_thread*)wi;
	y = thr->y;
	while (y < thr->lim_y)
	{
		x = -1;
		while (++x < WIDTH)
		{
			make_bur_first(x, y, &bur, thr);
			i = 0;
			while (i++ < thr->iter)
			{
				if (!make_bur_second(&bur))
					break ;
			}
			set_pixel(x, y, i, thr);
		}
		y++;
	}
	return (0);
}

void	burningship(t_win *win)
{
	int			i;
	pthread_t	tid[THREAD];

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
