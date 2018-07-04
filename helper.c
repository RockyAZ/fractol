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

void	make_zoom(t_win *win)
{
	int		i;
	double	cp;

	i = 0;
	cp = 0.3;
	while (i < ZOOM)
	{
		win->zooms[i] = cp;
		cp *= 1.1;
		i++;
	}
}

void	make_win(t_win *win)
{
	win->mouse_down = 0;
	win->is_text = 1;
	win->mouse_julia = 1;
	win->zoom_id = 0;
	win->move_size = 0.2;
}

int		make_threads_color(int i)
{
	if (i >= COLORS)
	{
		while (i >= COLORS && i > 0)
			i -= COLORS;
		if (i >= 0)
			return (i);
		else
		{
			while (i < 0)
				i++;
			return (i);
		}
	}
	return (i);
}

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
		win->thread[i].iter = 80;
		win->thread[i].zoom = 0.3;
		win->thread[i].move_x = 0;
		win->thread[i].move_y = 0;
		if (win->thr_color == 1)
			win->thread[i].color_id = make_threads_color(i);
		else if (win->thr_color == -1)
			win->thread[i].color_id = 0;
		win->thread[i].mouse.x = WIDTH / 2;
		win->thread[i].mouse.y = HEIGHT / 2;
		win->thread[i].dive = dive;
		i++;
	}
	make_win(win);
}

void		main_preparation(t_win *win, char *av)
{
	if ((win->mlx_ptr = mlx_init()) == NULL)
		error("mlx init error");
	if ((win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, av)) == NULL)
		error("window open error");
	if (HEIGHT / THREAD * THREAD != HEIGHT || THREAD < 1)
		error("invalid number of threads");
	win->name = av;
	win->thr_color = -1;
	make_thread(win);
	make_zoom(win);
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
	else if (!(ft_strcmp(av, "julia_3d")))
	{
		win->fract_id = 3;
		julia_3d(win);
	}
	else
		error("invalid name.\n\nNames to use:\n-mandelbrot\n-julia");
}
