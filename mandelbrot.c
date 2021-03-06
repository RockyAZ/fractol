/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:21:48 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/19 17:21:48 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_mandel_first(int x, int y, t_mandel *m, t_thread *t)
{
	m->buf_r = 1.5 * (x - WIDTH / 2) / (0.5 * t->zoom * WIDTH) + t->move_x;
	m->buf_i = (y - HEIGHT / 2) / (0.5 * t->zoom * HEIGHT) + t->move_y;
	m->rn[1] = 0;
	m->in[1] = 0;
}

int		make_mandel_second(t_mandel *man)
{
	man->rn[0] = man->rn[1];
	man->in[0] = man->in[1];
	man->rn[1] = man->rn[0] * man->rn[0] - man->in[0] * man->in[0] + man->buf_r;
	man->in[1] = 2 * man->rn[0] * man->in[0] + man->buf_i;
	if ((man->rn[1] * man->rn[1] + man->in[1] * man->in[1]) > 4)
		return (0);
	return (1);
}

void	*thread_mandelbrot(void *wi)
{
	t_mandel	man;
	t_thread	*thr;
	int			x;
	int			y;
	int			i;

	thr = (t_thread*)wi;
	y = thr->y;
	while (y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			make_mandel_first(x, y, &man, thr);
			i = -1;
			while (++i < thr->iter)
				if (!make_mandel_second(&man))
					break ;
			set_pixel(x, y, i, thr);
		}
		y++;
	}
	return (0);
}

void	mandelbrot(t_win *win)
{
	int			i;
	pthread_t	tid[THREAD];

	i = 0;
	prepare_draw(win);
	while (i < THREAD)
	{
		pthread_create(&tid[i], NULL, &thread_mandelbrot, &win->thread[i]);
		i++;
	}
	i = 0;
	while (i < THREAD)
		pthread_join(tid[i++], NULL);
	drawing(win);
}
