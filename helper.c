/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:40:05 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/21 17:40:05 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	main_preparation(t_win *win, char *av)
{
	int i;

	i = 0;
	if ((win->mlx_ptr = mlx_init()) == NULL)
		error("mlx init error");
	if ((win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "THE WINDOW")) == NULL)
		error("open windows error");
	if (HEIGHT / THREAD * THREAD != HEIGHT)
		error("invalid number of threads");
	while (i < THREAD)
	{
		win->thread[i].iter = 255;
		win->thread[i].zoom = 0.9;
		win->thread[i].move_x = 0;
		win->thread[i].move_y = 0;
		win->thread[i].mouse = &win->mouse;
		win->thread[i].i = i;
		i++;
	}
	if (!(ft_strcmp(av, "julia")))
		julia(win);
//	else if (!(ft_strcmp(av, "mandelbrot")))
//		mandelbrot(win);
	else
		error("invalid name.\n\nNames to use:\n-mandelbrot\n-julia");
}

/*
void	*thread_julia(void *vod)
{
	t_mandel	man;
	t_win		*win;
	int			i;
	int			x;
	int			y;

	win = (t_win*)vod;
	y = 0;
	man.buf_r = 1.5 * (win->mouse.x - WIDTH / 2) / (0.5 * win->zoom * WIDTH) + win->move_x;
	man.buf_i = (win->mouse.y - HEIGHT / 2) / (0.5 * win->zoom * HEIGHT) + win->move_y;
	while (y < HEIGHT)
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
*/