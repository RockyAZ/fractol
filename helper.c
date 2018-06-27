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
	int dive;

	i = 0;
	dive = HEIGHT / THREAD;
	if ((win->mlx_ptr = mlx_init()) == NULL)
		error("mlx init error");
	if ((win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, ft_itoa(THREAD))) == NULL)
		error("open windows error");
	if (HEIGHT / THREAD * THREAD != HEIGHT || THREAD < 1)
		error("invalid number of threads");
	prepare_draw(win);
	while (i < THREAD)
	{
		win->thread[i].y = i * dive;
		win->thread[i].lim_y = win->thread[i].y + dive;
		win->thread[i].iter = 300;
		win->thread[i].zoom = 0.9;
		win->thread[i].move_x = 0;
		win->thread[i].move_y = 0;
		win->thread[i].mouse.x = 500;
		win->thread[i].mouse.y = 400;
		win->thread[i].size_line = win->img.size_line;
		win->thread[i].img_ptr = win->img.ptr;
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
