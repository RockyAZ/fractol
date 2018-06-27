/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:04:24 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/27 18:04:08 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_reboot_fractol(t_win *win)
{
	make_thread(win);
	if (win->fract_id == 1)
		julia(win);
	else if (win->fract_id == 2)
		mandelbrot(win);
}

void	ft_scal_coord(int key, t_win *win)
{
	if (key == KEY_PLUS || key == KEY_MINUS)
	{
		if (key == KEY_PLUS)
			win->thread->zoom += 0.1;
		if (key == KEY_MINUS)
			win->thread->zoom -= 0.1;
		if (win->fract_id == 1)
			julia(win);
		else if (win->fract_id == 2)
			mandelbrot(win);
	}
}

void	ft_move_coord(int key, t_win *win)
{
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN || key == KEY_UP)
	{
		if (key == KEY_LEFT)
			win->thread->move_x += 0.2;
		if (key == KEY_RIGHT)
			win->thread->move_x -= 0.2;
		if (key == KEY_UP)
			win->thread->move_y += 0.2;
		if (key == KEY_DOWN)
			win->thread->move_y -= 0.2;
		if (win->fract_id == 1)
			julia(win);
		else if (win->fract_id == 2)
			mandelbrot(win);
	}
}

int		ft_keyhook(int key, t_win *win)
{
	if (key == 53)
		ft_exit(win);
	ft_move_coord(key, win);
	ft_scal_coord(key, win);
	if (key == KEY_R)
		ft_reboot_fractol(win);
	return (0);
}
