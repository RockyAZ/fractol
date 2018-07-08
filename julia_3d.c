/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:26:44 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/03 19:26:44 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_jul3d_first(int x, int y, t_julia *jul, t_thread *thr)
{
	jul->rn[1] = 1.5 * (x - WIDTH / 2) /
	((thr->zoom + thr->buf_r) * WIDTH) + thr->move_x;
	jul->in[1] = (y - HEIGHT / 2) /
	((thr->zoom + thr->buf_i) * HEIGHT) + thr->move_y;
}

int		make_jul3d_second(t_julia *jl, t_thread *thr)
{
	jl->rn[0] = jl->rn[1];
	jl->in[0] = jl->in[1];
	jl->rn[1] = ((jl->rn[0] * jl->rn[0]) -
	(jl->in[0] * jl->in[0])) + thr->buf_r;
	jl->in[1] = 2 * jl->rn[0] * jl->in[0] + thr->buf_i;
	if ((jl->rn[1] * jl->rn[1] + jl->in[1] * jl->in[1]) > 4)
		return (0);
	return (1);
}

void	*thread_julia_3d(void *wi)
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
		x = -1;
		while (++x < WIDTH)
		{
			make_jul3d_first(x, y, &jul, thr);
			i = -1;
			while (++i < thr->iter)
				if (!make_jul3d_second(&jul, thr))
					break ;
			set_pixel(x, y, i, thr);
		}
		y++;
	}
	return (0);
}

void	julia_3d(t_win *win)
{
	int			i;
	pthread_t	tid[THREAD];

	i = 0;
	prepare_draw(win);
	while (i < THREAD)
	{
		pthread_create(&tid[i], NULL, &thread_julia_3d, &win->thread[i]);
		i++;
	}
	i = 0;
	while (i < THREAD)
		pthread_join(tid[i++], NULL);
	drawing(win);
}
