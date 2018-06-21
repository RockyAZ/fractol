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

static int	ft_exit(t_win *win)
{
	system("leaks fractol");
	exit(EXIT_SUCCESS);
	return (0);
}

int			 main(int ac, char **av)
{
    t_win *win;

	if (ac == 1 || ac > 3)
	{
		error("invalid number of arguments");
		return (0);
	}
	if ((win = (t_win*)malloc(sizeof(t_win))) == NULL)
		error("t_win malloc error");
	preparation(win, av[1]);
	mlx_hook(win->win_ptr, 3, 0, &ft_exit, (void*)win);
	mlx_hook(win->win_ptr, 17, 0, &ft_exit, (void*)win);
	mlx_hook(win->win_ptr, 6, 0, &mouse_move, (void*)win);
	mlx_loop(win->mlx_ptr);
}
