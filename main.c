/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:20:15 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/19 14:20:17 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int ft_exit(t_win *win)
{
	exit(EXIT_SUCCESS);
	return (0);
}
/*
int main(int ac, char **av)
{
    t_win *win;

	win = (t_win*)malloc(sizeof(t_win));
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "THE WINDOW");
	win->iter = 256;
	win->zoom = 0.9;
	win->move_x = 0;
	win->move_y = 0;
	mandelbrot(win);
//	julia(win);
	mlx_hook(win->win_ptr, 3, 0, &ft_exit, (void*)win);
	mlx_hook(win->win_ptr, 17, 0, &ft_exit, (void*)win);
// 	mlx_hook(win->win_ptr, 6, 0, &mouse_move, (void*)win);	
	mlx_loop(win->mlx_ptr);
}
*/
int main(int ac, char **av)
{
    t_win *win;

	if (ac == 1 || ac > 3)
	{
		error("invalid number of arguments");
		return (0);
	}
	if ((win = (t_win*)malloc(sizeof(t_win))) == NULL)
		error("win malloc error");
	preparation(win, av[1]);
	mlx_hook(win->win_ptr, 3, 0, &ft_exit, (void*)win);
	mlx_hook(win->win_ptr, 17, 0, &ft_exit, (void*)win);
	mlx_hook(win->win_ptr, 6, 0, &mouse_move, (void*)win);
	mlx_loop(win->mlx_ptr);
}
