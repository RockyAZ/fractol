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

/*
** using t_mouse as simple coordinates structure
*/
void	*thread_julia(void *vod)
{
	t_mandel	man;
	t_win		*win;
	int			i;
	int			x;
	int			y;
	int			lim_y;

	win = (t_win*)vod;
	man.buf_r = 1.5 * (win->mouse.x - WIDTH / 2) / (0.5 * win->zoom * WIDTH) + win->move_x;
	man.buf_i = (win->mouse.y - HEIGHT / 2) / (0.5 * win->zoom * HEIGHT) + win->move_y;
	y = win->y;
	lim_y = win->lim_y;
	while (y < lim_y)
	{
		x = 0;
		while (x < WIDTH)
		{
			man.rn[1] = 1.5 * (x - WIDTH / 2) / (0.5 * win->zoom * WIDTH) + win->move_x;
			man.in[1] = (y - HEIGHT / 2) / (0.5 * win->zoom * HEIGHT) + win->move_y;
			i = 0;
			while (i < win->iter)
			{
				man.rn[0] = man.rn[1];
				man.in[0] = man.in[1];
				man.rn[1] = ((man.rn[0] * man.rn[0]) - (man.in[0] * man.in[0])) + man.buf_r;
				man.in[1] = 2 * man.rn[0] * man.in[0] + man.buf_i;
				if ((man.rn[1] * man.rn[1] + man.in[1] * man.in[1]) > 4)
					break ;
				i++;
			}
			set_pixel(x, y, i, win);
			x++;
		}
		y++;
	}
	return (0);
}

void	julia(t_win *win)
{
	int			i;
	int			dive;
	pthread_t	tid[THREAD];

	i = 0;
	dive = HEIGHT / THREAD;
	prepare_draw(win);
	while (i < THREAD)
	{
		printf("%d\n", i);
		pthread_create(&tid[i], NULL, thread_julia, (void*)win);
		i++;
printf("==============\n");
	}
	i = 0;
	while (i++ < THREAD)
		pthread_join(tid[i], NULL);
	drawing(win);
}
