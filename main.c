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

int	ft_exit(t_win *win)
{
	(void)win;
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_up_keyhook(int key, t_win *win)
{
	if (key == KEY_SHIFT_LEFT)
		win->left_shift = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_win *win;

	if (ac == 1 || ac > 3)
	{
		error("invalid number of arguments\
		\nUsage:   ./fractol [name of fractal]");
		return (0);
	}
	if ((win = (t_win*)malloc(sizeof(t_win))) == NULL)
		error("t_win malloc error");
	main_preparation(win, av[1]);
	mlx_hook(win->win_ptr, 2, 0, &ft_keyhook, (void*)win);
	mlx_hook(win->win_ptr, 3, 0, &ft_up_keyhook, (void*)win);
	mlx_hook(win->win_ptr, 17, 0, &ft_exit, (void*)win);
	mlx_hook(win->win_ptr, 4, 0, &mouse_down, (void*)win);
	mlx_hook(win->win_ptr, 5, 0, &mouse_up, (void*)win);
	mlx_hook(win->win_ptr, 6, 0, &mouse_move, (void*)win);
	mlx_loop(win->mlx_ptr);
}
