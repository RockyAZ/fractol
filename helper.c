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

void	preparation(t_win *win, char *av)
{
	if ((win->mlx_ptr = mlx_init()) == NULL)
		error("mlx init error");
	if ((win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "THE WINDOW")) == NULL)
		error("open windows error");
	if (HEIGHT / THREAD * THREAD != HEIGHT)
		error("invalid number of threads");
	win->iter = 256;
	win->zoom = 0.9;
	win->move_x = 0;
	win->move_y = 0;
	win->mouse.x = 0;
	win->mouse.y = 0;
	if (!(ft_strcmp(av, "julia")))
		julia(win);
	else if (!(ft_strcmp(av, "mandelbrot")))
		mandelbrot(win);
	else
		error("invalid name.\n\nNames to use:\n-mandelbrot\n-julia\n");

}