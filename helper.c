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

void	scal_size_changer(t_win *win, int bul)
{
	if (bul == 1)
	{
		win->zoom_id++;
		win->move_size /= 1.1109;
	}
	else if (bul == -1 && win->zoom_id - 1 >= 0)
	{
		win->zoom_id--;
		win->move_size *= 1.1109;
	}
}

void	what_fractal(t_win *win, char *av)
{
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
	else if (!(ft_strcmp(av, "burningship")))
	{
		win->fract_id = 4;
		burningship(win);
	}
	else
		error("invalid name!\nNames to use:\n-> mandelbrot\n-> julia\
		\n-> julia_3d\n-> burningship\n");
}

void	main_preparation(t_win *win, char *av)
{
	if ((win->mlx_ptr = mlx_init()) == NULL)
		error("mlx init error");
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, av);
	if (win->win_ptr == NULL)
		error("window open error");
	if (HEIGHT / THREAD * THREAD != HEIGHT || THREAD < 1)
		error("invalid number of threads");
	win->thr_color = -1;
	make_thread(win);
	make_zoom(win);
	what_fractal(win, av);
}
