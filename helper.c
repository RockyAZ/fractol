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

void	make_thread(t_win *win)
{
	int i;
	int dive;

	i = 0;
	dive = HEIGHT / THREAD;
	while (i < THREAD)
	{
		win->thread[i].y = i * dive;
		win->thread[i].lim_y = win->thread[i].y + dive;
		win->thread[i].iter = 128;
		win->thread[i].zoom = 0.9;
		win->thread[i].move_x = 0;
		win->thread[i].move_y = 0;
		win->thread[i].mouse.x = 500;
		win->thread[i].mouse.y = 400;
		win->thread[i].dive = dive;
		i++;
	}
}

void		main_preparation(t_win *win, char *av)
{
	if ((win->mlx_ptr = mlx_init()) == NULL)
		error("mlx init error");
	if ((win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, av)) == NULL)
		error("window open error");
	if (HEIGHT / THREAD * THREAD != HEIGHT || THREAD < 1)
		error("invalid number of threads");
	win->mouse_down = 0;
	win->is_text = 1;
	win->name = av;
	win->mouse_julia = 1;
	make_thread(win);
	if (!(ft_strcmp(av, "julia")))
	{
		win->fract_id = 1;
		julia(win);
	}
	else if (!(ft_strcmp(av, "mandelbrot")))
	{
		win->fract_id = 2;
		mandelbrot(win);
	}
	else
		error("invalid name.\n\nNames to use:\n-mandelbrot\n-julia");
}
