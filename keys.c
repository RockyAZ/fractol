/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:12:26 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/03 14:12:27 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_some_keys(int key, t_win *win)
{
	int i;

	i = 0;
	if (key == KEY_T)
		win->is_text *= -1;
	if (key == KEY_SHIFT_RIGHT)
		win->thr_color *= -1;
	if (key == KEY_SPACE)
		win->mouse_julia *= -1;
	if (key == KEY_SHIFT_LEFT)
		win->left_shift = 1;
	while (key == KEY_ENTER && i < THREAD)
	{
		win->thread[i].color_id += 1;
		if (win->thread[i].color_id >= COLORS)
			win->thread[i].color_id = 0;
		i++;
	}
	if (key == KEY_TAB)
	{
		win->fract_id += 1;
		if (win->fract_id > FRACTOLS)
			win->fract_id = 1;
	}
}

void	ft_iter_size(int key, t_win *win)
{
	int i;

	i = 0;
	while (i < THREAD && (key == KEY_MULTI || key == KEY_DIV))
	{
		if (key == KEY_MULTI)
		{
			if (win->thread[i].iter > 0 && win->thread[i].iter < 120)
				win->thread[i].iter += 1;
			else if (win->thread[i].iter > 120 && win->thread[i].iter < 300)
				win->thread[i].iter += 10;
			else if (win->thread[i].iter > 300 && win->thread[i].iter < 700)
				win->thread[i].iter += 22;
			else
				win->thread[i].iter += 50;
		}
		else if (key == KEY_DIV && win->thread[i].iter > 1)
		{
			if (win->thread[i].iter > 0 && win->thread[i].iter < 120)
				win->thread[i].iter -= 1;
			else if (win->thread[i].iter > 121)
				win->thread[i].iter -= 18;
		}
		i++;
	}
}

void	ft_scal_coord(int key, t_win *win)
{
	int i;

	i = -1;
	while (++i < THREAD && (key == KEY_PLUS || key == KEY_MINUS))
	{
		if (key == KEY_PLUS && win->zoom_id + 1 < ZOOM)
		{
			if (i == 0)
				scal_size_changer(win, 1);
			win->thread[i].zoom = win->zooms[win->zoom_id + 1];
		}
		else if (key == KEY_MINUS && win->zoom_id - 1 >= 0)
		{
			if (i == 0)
				scal_size_changer(win, -1);
			win->thread[i].zoom = win->zooms[win->zoom_id - 1];
		}
	}
}

void	ft_move_coord(int key, t_win *win)
{
	int i;

	i = 0;
	while (i < THREAD && (key == KEY_LEFT || key == KEY_RIGHT
	|| key == KEY_DOWN || key == KEY_UP))
	{
		if (key == KEY_LEFT)
			win->thread[i].move_x -= win->move_size;
		if (key == KEY_RIGHT)
			win->thread[i].move_x += win->move_size;
		if (key == KEY_UP)
			win->thread[i].move_y -= win->move_size;
		if (key == KEY_DOWN)
			win->thread[i].move_y += win->move_size;
		i++;
	}
}

int		ft_keyhook(int key, t_win *win)
{
	if (key == 53)
		ft_exit(win);
	if (key == KEY_R)
		make_thread(win);
	ft_move_coord(key, win);
	ft_scal_coord(key, win);
	ft_iter_size(key, win);
	ft_some_keys(key, win);
	if (win->fract_id == 1)
		julia(win);
	else if (win->fract_id == 2)
		mandelbrot(win);
	else if (win->fract_id == 3)
		julia_3d(win);
	else if (win->fract_id == 4)
		burningship(win);
	return (0);
}
