/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:44:58 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/21 16:44:59 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calling_fractal(t_win *win, int bul)
{
	int j;

	j = 0;
	if (win->mouse_julia == -1 && bul)
	{
		win->mouse_julia = 1;
		j = 1;
	}
	if (win->fract_id == 1 && (win->mouse_julia == 1 || win->m_down == 1))
		julia(win);
	if (win->fract_id == 3 && (win->mouse_julia == 1 || win->m_down == 1))
		julia_3d(win);
	if (win->fract_id == 2)
		mandelbrot(win);
	if (win->fract_id == 4)
		burningship(win);
	if (j == 1)
		win->mouse_julia = -1;
}

void	mouse_moving(int x, int y, t_win *win)
{
	int i;

	i = 0;
	while (i < THREAD)
	{
		if (win->thread[i].mouse.x < x || win->thread[i].mouse.x > x)
			win->thread[i].move_x +=
			mk_cx(win->thread[i].mouse.x, 0, win, 'r') - mk_cx(x, 0, win, 'r');
		if (win->thread[i].mouse.y < y || win->thread[i].mouse.y > y)
			win->thread[i].move_y +=
			mk_cx(0, win->thread[i].mouse.y, win, 'i') - mk_cx(0, y, win, 'i');
		i++;
	}
}

int		mouse_down(int button, int x, int y, t_win *win)
{
	win->mouse_button.x = x;
	win->mouse_button.y = y;
	if (button == MOUSE_MAIN)
		win->m_down = 1;
	return (0);
}

int		mouse_up(int button, int x, int y, t_win *win)
{
	int i;

	i = 0;
	(void)button;
	win->m_down = 0;
	while (x == win->mouse_button.x && y == win->mouse_button.y && i < THREAD)
	{
		if (win->left_shift)
		{
			if (i == 0)
				ft_scal_coord(KEY_MINUS, win);
			win->thread[i].move_x += mk_cx(x, 0, win, 'r') / 4;
			win->thread[i].move_y += mk_cx(0, y, win, 'i') / 4;
		}
		else if (!win->left_shift)
		{
			if (i == 0)
				ft_scal_coord(KEY_PLUS, win);
			win->thread[i].move_x += mk_cx(x, 0, win, 'r') / 4;
			win->thread[i].move_y += mk_cx(0, y, win, 'i') / 4;
		}
		i++;
	}
	calling_fractal(win, 1);
	return (0);
}

int		mouse_move(int x, int y, t_win *win)
{
	int i;

	i = 0;
	if (win->m_down == 1)
		mouse_moving(x, y, win);
	while (i < THREAD)
	{
		if ((win->fract_id == 1 || win->fract_id == 3) &&
		win->m_down == 0 && win->mouse_julia == 1)
		{
			win->thread[i].buf_r = mk_cx(win->thread[i].mouse.x, 0, win, 'r');
			win->thread[i].buf_i = mk_cx(0, win->thread[i].mouse.y, win, 'i');
		}
		win->thread[i].mouse.x = x;
		win->thread[i].mouse.y = y;
		i++;
	}
	calling_fractal(win, 0);
	return (0);
}
