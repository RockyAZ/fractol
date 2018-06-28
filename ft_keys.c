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

void	ft_iter_size(int key, t_win *win)
{
	int i;

	i = 0;
	if (key == KEY_MULTI || key == KEY_DIV)
	{
		while (i < THREAD)
		{
			if (key == KEY_MULTI)
				win->thread[i].iter += 1;
			if (key == KEY_DIV && win->thread[i].iter > 1)
				win->thread[i].iter -= 1;
			i++;
		}
	}
}

void	ft_scal_coord(int key, t_win *win)
{
	int i;

	i = 0;
	if (key == KEY_PLUS || key == KEY_MINUS)
	{
		while (i < THREAD)
		{
			if (key == KEY_PLUS)
				win->thread[i].zoom += 0.5;
			if (key == KEY_MINUS)
				win->thread[i].zoom -= 0.5;
			i++;
		}
	}
}

void	ft_move_coord(int key, t_win *win)
{
	int i;

	i = 0;
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN || key == KEY_UP)
	{
		while (i < THREAD)
		{
			if (key == KEY_LEFT)
				win->thread[i].move_x += 0.2;
			if (key == KEY_RIGHT)
				win->thread[i].move_x -= 0.2;
			if (key == KEY_UP)
				win->thread[i].move_y += 0.2;
			if (key == KEY_DOWN)
				win->thread[i].move_y -= 0.2;
			i++;
		}
	}
}

int		ft_keyhook(int key, t_win *win)
{
	if (key == 53)
		ft_exit(win);
	ft_move_coord(key, win);
	ft_scal_coord(key, win);
	ft_iter_size(key, win);
	if (key == KEY_R)
		make_thread(win);
	if (key == KEY_T)
		win->is_text *= -1;
	if (key == KEY_SPACE)
		win->mouse_julia *= -1;
/*
**
*/
	if (win->fract_id == 1)
		julia(win);
	else if (win->fract_id == 2)
		mandelbrot(win);
	return (0);
}
